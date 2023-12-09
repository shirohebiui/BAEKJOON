//https://www.acmicpc.net/problem/1197
#include <stdio.h>
#define MAX_EDGE 100001
#define MAX_VERTEX 10001

typedef struct graph_info {
    int A, B;
    int weight;
} graph;

graph queue[MAX_EDGE]; int rear;
graph best[MAX_VERTEX]; int best_rear;

void input_data();
int vertex, edge;

void swap(graph *a, graph *b);
void sort(int start, int end);

//여기까지 간선의 정보를 오름차순정렬하기위한 함수들
//아래부터 kruskal의 본격적 함수
int parent[MAX_VERTEX];
void init();
int find(int x);
void _union(int a, int b);

void kruskal();
int MST_wegiht; //MST 총 가중치 합

void test();

int main() {
    input_data();               //input data
    init();                     //init
    sort(0, rear-1);            //edge wegiht sorting
    kruskal();                  //kruskal algorithm
    printf("%d\n", MST_wegiht); //print entire mst weight
    //test();                     //test code
    return 0;
}

void input_data() {
    scanf("%d %d", &vertex, &edge);
    for(int i=0; i<edge; i++) {
        scanf("%d %d %d", &queue[rear].A, &queue[rear].B, &queue[rear].weight);
        rear++;
        // A <-> B 양방향간선 가중치는 weight
    }
}
void swap(graph *a, graph *b) {
    graph tmp = *a;
    *a = *b;
    *b = tmp;
}
void sort(int start, int end) {
    if(start >= end) return;
    int left = start, right = end;
    int pivot = queue[(start + right)/2].weight;
    while(left <= right) {
        while(queue[left].weight < pivot) left++;
        while(queue[right].weight > pivot) right--;
        if(left <= right)
            swap(&queue[left++], &queue[right--]);
    }
    sort(start, right);
    sort(left, end);
}

void init() {
    for(int i=1; i<=vertex; i++) {
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
void kruskal() {
    for(int i=0; i<rear; i++) {
        if(find(queue[i].A) != find(queue[i].B)) {
            _union(queue[i].A, queue[i].B);
            best[best_rear].A = queue[i].A;
            best[best_rear].B = queue[i].B;
            best[best_rear].weight = queue[i].weight;
            best_rear++;

            MST_wegiht += queue[i].weight;
        }
    }
}

void test() {
    printf("sort\n");
    for(int i=0; i<rear; i++) {
        printf("%d %d %d\n", queue[i].A, queue[i].B, queue[i].weight);
    }
    printf("best\n");
    for(int i=0; i<best_rear; i++) {
        printf("%d %d %d\n", best[i].A, best[i].B, best[i].weight);
    }
}
