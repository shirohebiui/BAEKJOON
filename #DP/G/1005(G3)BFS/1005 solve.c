//https://www.acmicpc.net/problem/1005
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1001
int dp[MAX]; //consider (workload)
char graph[MAX][MAX];

int vertex; //정점 갯수
int edge; //간선 갯수

void input_work() {
    for(int i=1; i<=vertex; i++)
        scanf(" %d", &dp[i]);
}

void input_graph() {
    int i, j;
    for(int t=1; t<=edge; t++) {
        scanf("%d %d", &i, &j);
        graph[j][i] = 1; //뒤에서부터 탐색할거니까 반대로 연결
    }
}

int dpbfs(int node) {
    int max = 0;
    for(int i=1; i<=vertex; i++) {
        if(graph[node][i]) { // 안 푼 문제
            graph[node][i] = 0; // 푼 문제로 체크
            max = max > dpbfs(i) ? max : dpbfs(i);
        }
    }
    dp[node] += max;
    return dp[node];
}

int main() {
    int TestCase; scanf("%d", &TestCase); //테스트 횟수
    while(TestCase--) {
        memset(graph, 0, sizeof(graph)); //그래프초기화
        scanf("%d %d", &vertex, &edge); //정점갯수
        input_work();
        input_graph();
        int goal; scanf(" %d", &goal);
        printf("%d\n", dpbfs(goal));
    }
    return 0;
}