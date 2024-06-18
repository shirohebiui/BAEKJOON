#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

int n, m;
char mem[8];
static inline void dfs(int idx, int cnt) {
	if(cnt == m) {
		FOR(i, 0, m-1) printf("%hhd ", mem[i]+1);
		printf("%hhd\n", mem[m-1]+1);
		return;
	}
	FOR(i, 0, n) {
		mem[cnt] = i;
		dfs(i, cnt+1);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	dfs(0, 0);
    return 0;
}