#include <stdio.h>
#include <string.h>
#define min(a,b) (a<b?a:b)

#define MAX_VTX 1001
#define INF 1e9

void input_data();
void init_graph();
int graph[MAX_VTX][MAX_VTX];
int vsize, esize, start, end;

void dijkstra();
int getMinVertex();
int dist[MAX_VTX];
int visited[MAX_VTX];

void test();

int main() {
    input_data();
    scanf(" %d %d", &start, &end);
    dijkstra();
    printf("%d\n", dist[end]);
    return 0;
}


void input_data() {
    scanf(" %d %d", &vsize, &esize);
    init_graph();
    int u, v, w;
    while(esize--) {
        scanf(" %d %d %d", &u, &v, &w);
        graph[u][v] = min(graph[u][v], w);
    }
}
void init_graph() {
    for(int i=1; i<=vsize; i++) {
        for(int j=1; j<=vsize; j++) {
            graph[i][j] = INF;
        }
    }
}

void dijkstra() {
    //memset(&visited[1], 0, vsize);      //visited init
    visited[start] = 1;

    for(int i=1; i<=vsize; i++) {    //dist init
        dist[i] = graph[start][i];
    }
    dist[start] = 0;
    //dijkstra algorithm
    int u, w;
    for(int i=1; i<=vsize; i++) {
        u = getMinVertex();
        visited[u] = 1;
        for(w=1; w<=vsize; w++) {
            if(!visited[w])
                dist[w] = min(dist[w], dist[u] + graph[u][w]);
        }
    }
}
int getMinVertex() {
    int min_v = 0;
    int min_w = INF;
    for(int i=1; i<=vsize; i++) {
        if(dist[i] < min_w && !visited[i]) {
            min_w = dist[i];
            min_v = i;
        }
    }
    return min_v;
}

void test() {
    // printf("graph\n");
    // for(int u=1; u<=vsize; u++) {
    //     for(int v=1; v<=vsize; v++) {
    //         if(graph[u][v] != INF) printf("%3d ", graph[u][v]);
    //         else                   printf("INF ");
    //     }
    //     printf("\n");
    // }
    // printf("\n");
    printf("dist\n");
    for(int i=1; i<=vsize; i++) {
        // printf("%d->%d : ", start, i);
        if(dist[i] != INF) printf("%d ", dist[i]);
        else               printf("INF ");
        // printf("\n");
    }
    printf("\n");
}

