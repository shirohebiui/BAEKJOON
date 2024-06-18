#include <stdio.h>
#define MAX 1000

int n, r;
char vis[MAX];
char que[MAX];

void dfs(int idx, int cnt) {
    if(cnt == r) {
        for(int i=0; i<r; i++) printf("%d ", que[i]);
        printf("\n");
        return;
    }
    for(int i=idx; i<=n; i++) {
        if(vis[i] == 0) {
            vis[i] = 1;
            que[cnt] = i;
            dfs(i,cnt+1);
            vis[i] = 0;
        }
    }

}

int main() {
    scanf("%d %d", &n, &r);
    dfs(1,0);
    return 0;
}