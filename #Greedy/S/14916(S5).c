#include "stdio.h"

int main() {
	int A=2, B=5;
	int V; scanf("%d", &V);
	for(int i=V/B; i>=0; i--) {
		for(int j=0; j<=V/A; j++) {
			if(i*B + j*A == V) {
				printf("%d\n", i+j);
				return 0;
			}
		}
	}
	printf("-1\n");
	return 0;
}