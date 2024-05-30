#include <stdio.h>
#define INF 99
#define MAX 100
#define min(a,b) (a<b?a:b)

char graph[MAX][MAX]; int vsize;

void input_init() {
    scanf("%d", &vsize);
    for(int i=0; i<vsize; i++) {
        for(int j=0; j<vsize; j++) {
            scanf(" %hhd", &graph[i][j]);
        }
    }
    for(int i=0; i<vsize; i++) {
        for(int j=0; j<vsize; j++) {
            if(!graph[i][j]) graph[i][j] = INF;
        }
    }
}

void flyod() {
    int k, u, v;
    for(k=0;k<vsize;k++) {
        for(u=0;u<vsize;u++) {
            for(v=0;v<vsize;v++) {
                graph[u][v] = min(graph[u][v], graph[u][k] + graph[k][v]);
            }
        }
    }
}

int main() {
    input_init();
    Plyod();
    for(int i=0; i<vsize; i++) {
        for(int j=0; j<vsize; j++) {
            printf("%d ", graph[i][j] != INF ? 1 : 0);
        }
        printf("\n");
    }
    return 0;
}