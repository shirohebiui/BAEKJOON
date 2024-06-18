#include <stdio.h>
#define MAX 1000

int n, r;
char vis[MAX];
char que[MAX];

void dfs(int cnt) {
    if(cnt == r) {
        for(int i=0; i<r; i++) printf("%d ", que[i]);
        printf("\n");
        return;
    }
    for(int i=1; i<=n; i++) {
        if(vis[i] == 0) {
            vis[i] = 1;
            que[cnt] = i;
            dfs(cnt+1);
            vis[i] = 0;
        }
    }

}

int main() {
    scanf("%d %d", &n, &r);
    dfs(0);
    return 0;
}