#include <stdio.h>
#include <string.h>
#define MAX 20001
#define R 11
#define B 22

char graph[MAX][2501]; int vsize, esize;
char visited[MAX];
char flag;

void dfs(int node, char color);

void test();

int parent[MAX];
void init(int n) {
    for(int i=0; i<=n; i++) {
        parent[i] = i;
    }
}

int find(int x) {
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void _union(int a, int b) {
    a = find(a);
    b = find(b);
    if(a < b) parent[a] = b;
    else parent[b] = a;
}

int main() {
    int TestCase; scanf("%d", &TestCase);
    while(TestCase--) {
        scanf("%d %d", &vsize, &esize);
        init(vsize);
        memset(graph, 0x00, sizeof(graph));
        memset(visited, 0x00, vsize+1);
        int u, v;
        flag = 0;
        while(esize--) {
            scanf("%d %d", &u, &v);
            u--; v--;
            graph[u][v/8] ^= 1<<(v%8);
            graph[v][u/8] ^= 1<<(u%8);
            _union(u, v);
            // graph[u][v] = 1;
            // graph[v][u] = 1;
        }
        for(int i=0; i<vsize; i++) {
            if(find(i) == i) {
                dfs(i, R);
            }
        }
        // test();
        if(flag) printf("NO\n");
        else     printf("YES\n");
    }
    return 0;
}

void dfs(int node, char color) {
    if(visited[node] != 0 && visited[node] == color) flag = 1;
    if(visited[node] != 0) return;
    if(flag) return;
    //coloring
    if(color == R) color = B;
    else           color = R;
    visited[node] = color;
    // printf("%d %d\n", node, color);
    //dfs
    for(int i=0; i<vsize; i++) {
        if(graph[node][i/8] & 1<<(i%8)) {
            dfs(i, color);
        }
    }
}

void test() {
    for(int i=0; i<vsize; i++) {
        for(int j=0; j<vsize; j++) {
            if(graph[i][j/8] & 1<<(j%8))
                printf("1");
            else printf("0");
        }
        printf("\n");
    }
}