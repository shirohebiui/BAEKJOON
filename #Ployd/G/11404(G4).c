#include <stdio.h>
#include <string.h>
#define MAX 100
#define INF 1e7 
//1->100 node까지 중간노드를 모두 거쳐 가야한다면
//(node max weight = 1e5)1e5 * 99가 최대 가중치
#define min(a,b) (a<b?a:b)

int dp[MAX][MAX];
void input();
int node;
void init();
void Floyd();
void print();


int main() {
	input(); //node, graph 가중치(비용)
	Floyd(); //Floyd Algorithm
    print();
	return 0;
}

void input() {
	scanf(" %d", &node);
	init();
	int edge; scanf(" %d", &edge);
	int start, end, weight;
	while(edge--) {
		scanf(" %d %d %d", &start, &end, &weight);
		dp[start-1][end-1] = min(dp[start-1][end-1], weight);
	}
}

void init() {
	for(int i=0; i<node; i++) {
		for(int j=0; j<node; j++)
			if(i != j) dp[i][j] = INF;
	}
}

void Floyd() { //Floyd-Warshall O(N^3)
	for(int k=0; k<node; k++) {
		for(int i=0; i<node; i++) {
			for(int j=0; j<node; j++) {
				if(dp[i][k] + dp[k][j] < dp[i][j])
					dp[i][j] = dp[i][k] + dp[k][j];
			}
		}
	}
}

void print() {
	for(int i=0; i<node; i++) {
		for(int j=0; j<node ; j++) {
			if(dp[i][j] >= INF) printf("0 ");
            else printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
}