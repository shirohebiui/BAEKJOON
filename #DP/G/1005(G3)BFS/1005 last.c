//https://www.acmicpc.net/problem/1005
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) (a>b?a:b)
#define MAX 1001
int dp[MAX]; //consider (workload)
char graph[MAX][MAX];

int vsize; //정점 갯수
int esize; //간선 갯수

void input_work() {
    for(int i=1; i<=vsize; i++)
        scanf(" %d", &dp[i]);
}

void input_graph() {
    int i, j;
    for(int t=1; t<=esize; t++) {
        scanf("%d %d", &i, &j);
        graph[j][i] = 1; //뒤에서부터 탐색할거니까 반대로 연결
    }
}

int dpbfs(int node) {
    int cost = 0;
    for(int i=1; i<=vsize; i++) {
        if(graph[node][i]) { // 안 푼 문제
            graph[node][i] = 0; // 푼 문제로 체크
            cost = max(cost, dpbfs(i));
        }
    }
    dp[node] += cost;
    return dp[node];
}

int main() {
    int TestCase; scanf("%d", &TestCase); //테스트 횟수
    while(TestCase--) {
        scanf("%d %d", &vsize, &esize); //정점갯수
        memset(graph, 0x00, sizeof(graph));
        input_work();
        input_graph();
        int dest; scanf(" %d", &dest); //목표노드
        printf("%d\n", dpbfs(dest));
    }
    return 0;
}