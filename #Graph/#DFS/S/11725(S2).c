#include <stdio.h>
#include <stdlib.h>
#define max_vsize 100001

typedef struct G{
    int adj;
    struct G *link;
}G;

G graph[max_vsize]; int vsize;
char visited[max_vsize];
int parent[max_vsize];

void init_graph(int vsize) {
    for(int i=0; i<vsize; i++) {
        graph[i].link = NULL;
    }
}

void insert(int u, int w) {
    G *v = &graph[u];
    while(v->link) {
        v = v->link;
        if(v->adj == w) return;
    }
    G *new = (G *)malloc(sizeof(G));
    v->link = new;
    new->adj = w;
    new->link = NULL;
}

void dfs(int node) {
    visited[node] = 1;
    for (G* v = &graph[node]; v; v = v->link) {
        if (!visited[v->adj]) {
            parent[v->adj] = node;
            dfs(v->adj);
        }
    }
}

void clear() {
    for(int i=1; i<=vsize; i++) {
        if(graph[i].link == NULL) continue;
        G *v = graph[i].link;
        while(v->link) {
            G *tmp = v;
            v = v->link;
            free(tmp);
        }
    }
}

void test();

int main() {
    visited[0] = 1;
    scanf(" %d", &vsize);
    init_graph(vsize);
    for(int i=1; i<=vsize; i++) {
        int u, w; scanf("%d %d", &u, &w);
        insert(u,w); insert(w,u); //무방향그래프, range : 0 ~ vsize-1
    }
    dfs(1);
    for(int v=2; v<=vsize; v++) {
        printf("%d\n", parent[v]);
    }
    clear();
    return 0;
}

void test() {
    printf("\n");
    for(int i=1; i<=vsize; i++) {
        G *v = &graph[i];
        printf("%d->", i);
        while(v->link) {
            v = v->link;
            printf("%d->", v->adj);
        }
        printf("\n");
    }
}