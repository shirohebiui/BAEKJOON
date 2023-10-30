#include <stdio.h>
#include <memory.h>
#define MAX 1001

int visit[MAX];
int data[MAX][MAX];
int num_node, num_line, start_node;

void input_data(int count) {
    int start, end;
    while(count--) {
        scanf("%d %d", &start, &end);
        data[start][end] = 1;
        data[end][start] = 1;
    }
}

void dfs(int node) {
    if(visit[node] == 0) {
        visit[node] = 1;
        printf("%d ", node);
        for(int i=0; i<MAX; i++) {
            if(data[node][i] == 1) {
                dfs(i);
            }
        }
    }
}

int queue[MAX];
int front = 0, rear = 0;
void bfs(int node) {
    if(visit[node] == 0) {
        visit[node] = 1;
        queue[rear++] = node;
    }
    for(int i=0; i<MAX; i++) {
        if(data[node][i] == 1 && visit[i] == 0) {
            visit[i] = 1;
            queue[rear++] = i;
        }
    }
    while(front < rear) {
        bfs(queue[front++]);
    }
}

void print_queue() {
    for(int i=0; i<rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    scanf("%d %d %d", &num_node, &num_line, &start_node);

    input_data(num_line);
    memset(visit, 0, MAX*sizeof(int));

    //dfs
    dfs(start_node);
    printf("\n");
    memset(visit, 0, MAX*sizeof(int));

    //bfs
    bfs(start_node);
    print_queue();

    return 0;
}