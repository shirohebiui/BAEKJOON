#include <stdio.h>
#define Limit 100001

int goal, input;

char vis[Limit];
int que[650001];
int front, rear, prear;
int time, cnt;
void bfs() {
    int tmp;
    vis[input] = 1;
    que[rear++] = input;
    ++time;
    if(que[front] == goal) {
        ++cnt; return;
    }
    while(front < rear) {
        prear = rear;
        while(front < prear) {
            vis[que[front]] = 1;
            if(que[front] == goal) ++cnt;

            tmp = que[front] + 1;
            if(tmp < Limit && !vis[tmp]) {
                que[rear++] = tmp;
            }
            
            tmp = que[front] - 1;
            if(tmp >= 0 && !vis[tmp]) {
                que[rear++] = tmp;
            }
            
            tmp = que[front] * 2;
            if(tmp < Limit && !vis[tmp]) {
                que[rear++] = tmp;
            }
            ++front;
        }
        if(cnt) return;
        ++time;
    }
}

int main(){
    scanf(" %d %d", &input, &goal);
    bfs();
    printf("%d\n%d\n", time-1, cnt);
    return 0;
}
