#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int goal, input;
char command[4] = "DSLR";

typedef struct data{
    short res;
    char cmd;
    struct data *parent;
}data;

data queue[10002]; int front, rear;
void init();

char visited[10001];

void DSLR(data *s) {
    short prev = s->parent->res;
    switch(s->cmd) {
        case 'D':
            s->res = (prev<<1)%10000;
            break;
        case 'S':
            s->res = (prev == 0 ? 9999 : prev-1);
            break;
        case 'L':
            s->res = (prev/1000 + prev%1000*10);
            break;
        case 'R':
            s->res = ((prev%10)*1000 + prev/10);
            break;
    }
}

void bfs() {
    int prear, i;
    for(rear=1;rear<5;rear++) {
        if(queue[rear].res == goal) return;
    }
    while(front < rear) {
        prear = rear;
        while(front < prear) {
            for(i=0; i<4; i++) {
                queue[rear].parent = &queue[front];
                queue[rear].cmd = command[i];
                DSLR(&queue[rear]);

                if(queue[rear].res == goal) return;
                if(visited[queue[rear].res] == 0) {
                    visited[queue[rear].res] = 1;
                    rear++;
                }
            }
            front++;
        }
    }
}

char cal[5000];
void answer() {
    data *p = &queue[rear];
    int i = 0;
    while(p->parent != NULL) {
        cal[i++] = p->cmd;
        p = p->parent;
    }
    while(i--) printf("%c", cal[i]);
    printf("\n");
}

int main(){
    int tc; scanf("%d", &tc);
    while(tc--) {
        scanf(" %d %d", &input, &goal);
        init();
        bfs();
        answer();
    }
    return 0;
}

void init() {
    visited[input] = 1;
    front = rear = 1;
    queue[0].parent = NULL;
    queue[0].cmd = '\0';
    queue[0].res = input;
    for(int i=0; i<4; i++) {
        queue[rear].parent = &queue[0];
        queue[rear].cmd = command[i];
        DSLR(&queue[rear]); rear++;
    }
    memset(visited, 0x00, sizeof(visited));
}