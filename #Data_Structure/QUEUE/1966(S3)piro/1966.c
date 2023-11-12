#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int rear, find_idx, find_prio;
int prio_cnt[10];

typedef struct _doc {
	int idx; int prio;
	struct _doc *prev;
	struct _doc *next;
} doc;

doc *head, *tail;

void init(void) {
    head = (doc *)malloc(sizeof(doc));
	tail = (doc *)malloc(sizeof(doc));
	head->next = tail;
	head->prev = head;
	tail->next = tail;
	tail->prev = head;

    for(int i=1; i<10; i++) prio_cnt[i] = 0;
}
void memfree() {

}
doc *pop() {
    doc *s = head->next;
	s->prev->next = s->next;
	s->next->prev = s->prev;
    prio_cnt[s->prio]--;
	return s;
}

void push(doc in) {
    doc *s = (doc *)malloc(sizeof(doc));
    *s = in;
    s->prev = tail->prev;
    s->next = tail;
    tail->prev->next = s;
    tail->prev = s;
    prio_cnt[s->prio]++;
}

void print_queue();
void input_data() {
    doc s;
    for(int idx=0; idx<rear; idx++) {
        scanf(" %d", &s.prio);
        s.idx = idx;
        push(s);
        if(idx == find_idx) find_prio = s.prio;
    }
    // print_queue();
}

int is_first(int prio) {
    for(int i=prio+1; i<10; i++) {
        if(prio_cnt[i]) return 0; 
    }
    return 1;
}
int find_print(int idx) {
    int cnt = 1;
    doc *p = (doc *)malloc(sizeof(doc));
    while(1) {
        // print_queue();
        p = pop();
        if(is_first(p->prio)) {
            if(p->idx == find_idx) {
                return cnt;
            }
            cnt++;
        } else {
            push(*p);
        }
    }
    return -1;
}


int main() {
    int TestCase; scanf("%d", &TestCase);
    while(TestCase--) {
        init();
        scanf("%d %d", &rear, &find_idx);
        input_data();
        printf("%d\n", find_print(find_idx));
    }
    return 0;
}

void print_queue() {
    doc *p = (doc *)malloc(sizeof(doc));
    p = head->next;
    printf("_prio : ");
    while(p != tail) {
        printf("[%d] ", p->prio);
        p = p->next;
    }
    printf("\n");
    p = head->next;
    printf("__idx : ");
    while(p != tail) {
        printf("[%d] ", p->idx);
        p = p->next;
    }
    printf("\n\n");
}