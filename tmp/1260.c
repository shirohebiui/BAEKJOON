#include <stdio.h>
#define MAX 1001
int DFS_V[MAX] = {0, };
int BFS_V[MAX] = {0, };
int graph[MAX][MAX] = {0, };
int queue[MAX];

void DFS(int V, int vertices);
void BFS(int v, int vertices);

int main()
{
    int vertices, line, V, i, j;
    scanf("%d %d %d", &vertices, &line, &V);

    while (line--) {
        scanf("%d %d", &i, &j);
        graph[i][j] = 1;
        graph[j][i] = 1;
    }

    DFS(V, vertices);
    printf("\n");
    BFS(V, vertices);
    for(int i=0; i<vertices)
    return 0;
}

void DFS(int V, int vertices)
{
    int i;
    DFS_V[V] = 1;
    printf("%d ", V);
    for(i=0;i<vertices;i++) {
        if(DFS_V[i] == 0 && graph[V][i] != 0) {
            DFS(i, vertices);
        }
    }
}
void BFS(int V, int vertices)
{
    int count = 0;
    int i;
    while(count != vertices) {
    for(i=0;i<vertices;i++) {
        if(BFS_V[i] == 0 && graph[V][i] != 0) {
            BFS_V[i] = 1;
            queue[count++] = i;
            BFS(i, vertices);
        }
    }}
}