#include <stdio.h>
#define Limit 131073

int goal, input;

void init();

char vis[Limit];
int que[300001];
int front, rear, prear;

int time;
void bfs() {
    int tmp;
    vis[input] = 1;
    que[rear++] = input;
    if(que[front] == goal) return;
    time++;
    while(front < rear) {
        prear = rear;
        while(front < prear) {
            // +1, -1, *2
            tmp = que[front] + 1;
            if(tmp < Limit && tmp >= 0 && !vis[tmp]) {
                if(tmp == goal) return;
                vis[tmp] = 1;
                que[rear++] = tmp;
            }
            
            tmp = que[front] - 1;
            if(tmp < Limit && tmp >= 0 && !vis[tmp]) {
                if(tmp == goal) return;
                vis[tmp] = 1;
                que[rear++] = tmp;
            }
            
            tmp = que[front] * 2;
            if(tmp < Limit && tmp >= 0 && !vis[tmp]) {
                if(tmp == goal) return;
                vis[tmp] = 1;
                que[rear++] = tmp;
            }
            front++;
        }
        time++;
    }
}

int main(){
    scanf(" %d %d", &input, &goal);
    bfs();
    printf("%d\n", time);
    return 0;
}
