#include <stdio.h>

char out[20][21];

int main() {
	int n; scanf("%d", &n);
	for(int i=0; i<n; i++) {
	for(int j=0; j<n; j++) {
		out[i][j] = ' ';
	}
	}
	int k = n--;
	while(k--) {
		out[k][0] = '*';
		out[0][k] = '*';
		out[k][n] = '*';
		out[n][k] = '*';

		out[k][n-k] = '*';
		out[k][k] = '*';

		out[k][n+1] = '\0';
	}
	for(int i=0; i<n+1; i++) {
		printf("%s\n", out[i]);
	}
	return 0;
}