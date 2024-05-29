#include <stdio.h>
#include <string.h>
#define min(a,b) (a<b?a:b)
#define INF 1e9
int graph[20][20];         //graph 무방향
int dist[20];              //dijkstra에서 쓸 거리기록용 배열
int parent[20]; //지나온 정점을 기록
char visited[20];
int start, end, vsize, esize;

void init();
void test();

int GetMinVertex() {
    int min_v = 0;
    int min_w = INF;
    for(int i=0; i<vsize; i++) {
        if(dist[i] < min_w && !visited[i]) {
            min_w = dist[i];
            min_v = i;
        }
    }
    return min_v;
}

void dijkstra() {
    visited[start] = 0;

    for(int i=0; i<vsize; i++) {    //dist init
        dist[i] = graph[start][i];
    }
    dist[start] = 0;
    //dijkstra algorithm
    int u, w;
    for(int i=0; i<vsize; i++) {
        u = GetMinVertex();
        visited[u] = 1;
        for(w=0; w<vsize; w++) {
            if(!visited[w]) {
                if(dist[w] > dist[u] + graph[u][w]) {
                    dist[w] = dist[u] + graph[u][w];
                    parent[w] = u;
                }
            }
                // dist[w] = min(dist[w], dist[u] + graph[u][w]);
        }
    }
}

void path(int node) {
    if(parent[node] == -1) return;
    path(parent[node]);
    printf("%d ", parent[node]);
}

int main() {
    int TestCase; scanf("%d", &TestCase);
    for(int num = 1; num<=TestCase; num++) {
        //input
        scanf(" %d %d", &esize, &vsize);
        init();
        int u, v, w;
        while(esize--) {
            scanf(" %d %d %d", &u, &v, &w);
            graph[u][v] = graph[v][u] = min(graph[u][v], w);
            // printf("%d %d %d %d\n", u, v, w, graph[u][v]);
        }

        //dijkstra algorithm
        dijkstra();
        // test();

        //answer
        if(dist[end] == INF) {
            printf("Case #%d: -1\n", num);
        } else {
            printf("Case #%d: %d ", num, start);
            path(end);
            printf("%d\n", end);
        }
    }
    return 0;
}

void init() {
    start = 0; end = vsize - 1;
    memset(visited, 0x00, vsize);
    
    for(int i=0; i<vsize; i++) {
        for(int j=0; j<vsize; j++) {
            graph[i][j] = INF;
        }
        parent[i] = -1;
    }
}

void test() {
    // printf("graph\n");
    // for(int u=0; u<vsize; u++) {
    //     for(int v=0; v<vsize; v++) {
    //         if(graph[u][v] != INF) printf("%3d ", graph[u][v]);
    //         else                   printf("INF ");
    //     }
    //     printf("\n");
    // }
    // printf("\n");
    printf("dist\n");
    for(int i=0; i<vsize; i++) {
        // printf("%d->%d : ", start, i);
        if(dist[i] != INF) printf("%d ", dist[i]);
        else               printf("INF ");
        // printf("\n");
    }
    printf("\n");
    printf("parent\n");
    for(int i=0; i<vsize; i++) {
        printf("%d ", parent[i]);
    }
    printf("\n");
}
