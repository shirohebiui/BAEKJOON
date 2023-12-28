#include <stdio.h>
#define MAX 600003

typedef struct dll{
    char ch;
    struct dll *next;
    struct dll *prev;
}dll;

struct dll *head, *tail;
dll text[MAX]; int size;

dll *cursur;

void init() {
    head = &text[MAX-1];
    tail = &text[MAX-2];
    head->prev = head;
    head->next = tail;
    tail->prev = head;
    tail->next = tail;
    cursur = tail;
}

void L() {
    if(cursur->prev == head) return;
    cursur = cursur->prev;
}

void D() {
    if(cursur == tail) return;
    cursur = cursur->next;
}

void B() {
    if(cursur->prev == head) return;
    cursur->prev = cursur->prev->prev;
    cursur->prev->next = cursur;
}

void P(char input) {
    dll *i = &text[size++];
    i->ch = input;
    i->next = cursur;
    i->prev = cursur->prev;
    cursur->prev->next = i;
    cursur->prev = i;
}

void answer() {
    cursur = head;
    while(cursur->next != tail) {
        cursur = cursur->next;
        printf("%c", cursur->ch);
    }
    printf("\n");
}

int main() {
    init();

    //input
    char str[100001]; scanf("%s", str);
    char *ptr = str;
    while(*ptr != '\0') P(*ptr++);

    int TestCase; scanf(" %d", &TestCase);
    while(TestCase--) {
        char mode; scanf(" %c", &mode);
        switch (mode)
        {
        case 'L':
            L();
            break;
        case 'D':
            D();
            break;
        case 'B':
            B();
            break;
        case 'P':
            char input; scanf(" %c", &input);
            P(input);
            break;
        default:
            break;
        }
    }
    //answer
    answer();
    return 0;
}