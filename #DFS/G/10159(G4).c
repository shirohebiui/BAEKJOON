#include <stdio.h>
#include <string.h>
int vsize, esize;

char graph[100][100];

char visited[100];
int cnt;

void dfs(char node, char mod) {
    if(visited[node]) return;
    visited[node] = 1;
    cnt++;
    for(int i=0; i<vsize; i++) {
        if(graph[node][i] & mod) dfs(i, mod);
    }
}

int main() {
    scanf("%d %d", &vsize, &esize);
    while(esize--) {
        char u, v; scanf(" %d %d", &u, &v);
        u--; v--;
        graph[u][v] |= 0x01;
        graph[v][u] |= 0x02;
    }
    for(int i=0; i<vsize; i++) {
        cnt = -1;
        dfs(i, 1);
        memset(visited, 0x00, sizeof(visited));
        dfs(i, 2);
        memset(visited, 0x00, sizeof(visited));
        printf("%d\n", vsize-cnt);
    }
    return 0;
}