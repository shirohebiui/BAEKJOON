#include <stdio.h>
#define MAX 10

int arr[MAX] = {7,2,3,9,28,11};

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int i, j;
    for(i=0; i<MAX; i++) {
        for(j=0; j<MAX-i; j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
    
    for(i=0; i<MAX; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for(i=0; i<MAX; i++) {
        for(j=0; j<MAX-i; j++) {
            if(arr[j] < arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
    
    for(i=0; i<MAX; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}