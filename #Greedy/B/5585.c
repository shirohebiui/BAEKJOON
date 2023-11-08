#include "stdio.h"

int coins[10] = {500, 100, 50, 10, 5, 1};
int select[10];
int count;

void greedy(int max, int V) {
	for(int i=0; i<max; i++) {
		int cnt = V / coins[i];
		select[i]= cnt;
		count += cnt;
		V -= cnt * coins[i];
	}
}

int main() {
	int pay;
	scanf("%d", &pay);
	greedy(6, 1000-pay);
	printf("%d\n", count);
	return 0;
}