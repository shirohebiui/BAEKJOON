#include <stdio.h>
#define MAX 50

int arr1[MAX], arr2[MAX];

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void qsort(int *arr, int front, int end) {
    if(front >= end) return;
    int left = front;
    int right = end;
    int pivot = arr[(left+right)/2];
    while(left<=right) {
        while(arr[left] < pivot) left++;
        while(arr[right] > pivot) right--;
        if(left <= right) swap(&arr[left++], &arr[right--]);
    }
    qsort(arr, front, right);
    qsort(arr, left, end);
}

int main() {
    //input
    int N; scanf("%d" ,&N);
    for(int i=0; i<N; i++) scanf(" %d", &arr1[i]);
    for(int i=0; i<N; i++) scanf(" %d", &arr2[i]);

    qsort(arr1, 0, N-1);
    qsort(arr2, 0, N-1);
    long sum = 0;
    N--;
    for(int i=0; i<=N; i++) {
        sum += arr1[i] * arr2[N-i];
    }
    printf("%ld\n", sum);
    return 0;
}