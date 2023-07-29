#include <stdio.h>
#define MAX 10
#define MAX_NUM 1000

int arr[MAX] = {7,2,3,9,28,11};

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int i, j;
    int min;
    int ch;
    for(i=0; i<MAX; i++) {
        ch = i;
        min = MAX_NUM;
        for(j=i; j<MAX ;j++) {
            if(min > arr[j]) {
                min = arr[j];
                ch = j;
            }
        }
        if(ch != i)
            swap(&arr[i], &arr[ch]);
    }

    for(i=0; i<MAX; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}