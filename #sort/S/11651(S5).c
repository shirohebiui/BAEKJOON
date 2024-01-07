#include <stdio.h>
#include <stdlib.h>

typedef struct pos{
    int x;
    int y;
}pos;

pos arr[100001];

int cmp(const void *s1, const void *s2) {
    if(((pos*)s1)->y > ((pos*)s2)->y) return 1;
    if(((pos*)s1)->y ==((pos*)s2)->y) {
        if(((pos*)s1)->x > ((pos*)s2)->x) return 1;
    }
    return 0;
}

int main() {
    int N; scanf("%d", &N);
    for(int i=0; i<N; i++) scanf(" %d %d", &arr[i].x, &arr[i].y);
    qsort(arr, N, sizeof(pos), cmp);
    for(int i=0; i<N; i++) printf("%d %d\n", arr[i].x, arr[i].y);
    return 0;
}