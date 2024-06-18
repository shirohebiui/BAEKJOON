#include <stdio.h>
#define Limit 100001

int goal, input;

char vis[Limit];
typedef struct node{
    int pos;
    struct node *prev;
}node;
node que[300001];
int front, rear, prear;

int time;
void bfs() {
    int tmp;
    vis[input] = 1;
    que[rear].prev = NULL;
    que[rear++].pos = input;
    time++;
    while(front < rear) {
        prear = rear;
        while(front < prear) {
            // +1, -1, *2
            tmp = que[front].pos + 1;
            if(tmp < Limit && !vis[tmp]) {
                // printf("%d %d\n", time, tmp);
                vis[tmp] = 1;
                que[rear].prev = &que[front];
                que[rear++].pos = tmp;
                if(tmp == goal) return;
            }
            
            tmp = que[front].pos - 1;
            if(tmp >= 0 && !vis[tmp]) {
                // printf("%d %d\n", time, tmp);
                vis[tmp] = 1;
                que[rear].prev = &que[front];
                que[rear++].pos = tmp;
                if(tmp == goal) return;
            }
            
            tmp = que[front].pos * 2;
            if(tmp < Limit && !vis[tmp]) {
                // printf("%d %d\n", time, tmp);
                vis[tmp] = 1;
                que[rear].prev = &que[front];
                que[rear++].pos = tmp;
                if(tmp == goal) return;
            }
            front++;
        }
        time++;
    }
}

int main(){
    scanf(" %d %d", &input, &goal);
    if(input == goal) {
        printf("0\n%d\n", goal);
        return 0;
    }
    bfs();
    printf("%d\n", time);
    int stack[100001] = {goal}, top = 0;
    node *nav = &que[rear-1];
    while(nav != NULL) {
        stack[top++] = nav->pos;
        nav = nav->prev;
    }
    while(top--) {
        printf("%d ", stack[top]);
    }
    return 0;
}