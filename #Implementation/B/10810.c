#include <stdio.h>
int bucket[101];

int main() {
    int n,m;scanf("%d %d",&n,&m);
    while(m--) {
        int s,e,k; scanf(" %d %d %d",&s,&e,&k);
        while(s<=e) bucket[s++]=k;
    }
    for(int i=1; i<=n; i++) {
        printf("%d ", bucket[i]);
    }
    printf("\n");
}