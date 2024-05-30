#include <stdio.h>
#define MAX 8

int n, r;
char vis[MAX];
short que[MAX];
short arr[MAX];
char num[10000];

void dfs(int cnt) {
    if(cnt == r) {
        for(int i=0; i<r; i++) printf("%d ", que[i]);
        printf("\n");
        return;
    }
    for(int i=0; i<n; i++) {
        if(vis[i] == 0) {
            vis[i]++;
            que[cnt] = arr[i];
            dfs(cnt+1);
            vis[i]--;
        }
    }
}

int main() {
    scanf("%d %d", &n, &r);
    short in;
    for(int i=0; i<n; i++) {
        scanf(" %hd", &in); num[in] = 1;
    }
    int cnt = 0;
    for(int i=1; i<=10000; i++) {
        if(num[i]) arr[cnt++] = i;
    }
    dfs(0);
    return 0;
}