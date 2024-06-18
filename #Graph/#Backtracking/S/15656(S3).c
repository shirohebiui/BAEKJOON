#include <stdio.h>
#define MAX 7

int base[MAX];
int que[MAX];
int N, M;

void dfs(int idx) {
    if(idx == M) {
        for(int i=0; i<M; i++) printf("%d ",que[i]);
        printf("\n");
        return;
    }

    for(int i=0; i<N; i++) {
        que[idx] = base[i]; 
        dfs(idx+1);
    }
}

void swap(int *a, int *b) {
    int tmp = *a; *a=*b; *b = tmp;
}

void qsort(int *arr, int start, int end) {
    if(start >= end) return;
    int left = start;
    int right = end;
    int pivot = base[(left+right)/2];
    while(left <= right) {
        while(arr[left] < pivot) left++;
        while(arr[right] > pivot) right--;
        if(left <= right) swap(&arr[left++], &arr[right--]);
    }
    qsort(arr, start, right);
    qsort(arr, left, end);
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++) {
        scanf(" %d", &base[i]);
    }
    qsort(base, 0, N-1);
    dfs(0);
    return 0;
}