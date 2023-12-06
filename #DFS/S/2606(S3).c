#include <stdio.h> 
#define MAX 101

void input_data();
int graph[MAX][MAX]; // A-B
int vertex, edge;

void dfs(int node);
int visited[MAX], cnt; 

int main() {
    input_data();
    dfs(1);
    printf("%d\n", cnt-1);
    return 0;
}

void input_data() {
    scanf(" %d", &vertex);
    scanf(" %d", &edge);
    int A, B;
    for(int i=0; i<edge; i++) {
        scanf(" %d %d", &A, &B);
        graph[A][B] = 1;
        graph[B][A] = 1;
    }
}

void dfs(int node) {
    if(visited[node] == 0) {
        visited[node] = 1;
        cnt++;
        for(int i=2; i<MAX; i++) { //node 1 start, 2부터 탐색
            if(graph[node][i] == 1)
                dfs(i);
        }
    }
}
