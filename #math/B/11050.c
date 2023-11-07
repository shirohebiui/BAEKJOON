#include <stdio.h>
#define MAX 1000
int select[MAX];
int end, count, n, k;


//nCr
void dfs(int idx, int cnt) {
    if(cnt == k) {
        count++;
        return;
    }
    for(int i=idx; i<n; i++) {
        if(select[i] == 0) {
            select[i] = 1;
            dfs(i, cnt+1);
            select[i] = 0;
        }
    }
}
int main()
{
    scanf("%d %d", &n, &k);
    dfs(0, 0);
    printf("%d\n", count);
	return 0;
}