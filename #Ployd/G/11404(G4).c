#include <stdio.h>
#include <string.h>
#define MAX 101
#define INF 1e9
int node = MAX;
// a b c d e

int dp[MAX][MAX];

void init() {
	for(int i=0; i<node; i++) {
		for(int j=0; j<node; j++) {
			dp[i][j] = INF;
		}
	}
	for(int i=0; i<node; i++)
		dp[i][i] = 0;
}

void print() {
	for(int i=0; i<node; i++) {
		for(int j=0; j<node ; j++) {
			if(dp[i][j] == INF)
				printf("0 ");
			else
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
}

void dp_floyd() {
	for(int k=0; k<node; k++) {
		for(int i=0; i<node; i++) {
			for(int j=0; j<node; j++) {
				// if(dp[i][k] != 0 && dp[k][j] != 0)
				if(dp[i][k] + dp[k][j] < dp[i][j])
					dp[i][j] = dp[i][k] + dp[k][j];
				
			}
		}
	}
}

int main() {
	init();
	int n; scanf("%d", &n); node = n;
	int m; scanf("%d", &m);
	int a, b, c;
	while(m--) {
		scanf("%d %d %d", &a, &b, &c);
		if(dp[a-1][b-1] > c)
			dp[a-1][b-1] = c;
	}
	dp_floyd();
	print(); 
	return 0;
}
/*
4
6
1 2 1
1 3 2
2 1 2
2 3 1
3 1 2
3 2 3
*/