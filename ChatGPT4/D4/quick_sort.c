#include <stdio.h>

/* int data[100] = { 49, 56, 23, 10, 78, 3, 30, 19, 66, 91, 53, 70, 41, 45, 84, 61, 14, 5, 77, 36, 
                    99, 72, 83, 47, 90, 25, 57, 79, 21, 89, 34, 60, 9, 58, 68, 67, 39, 6, 51, 93, 
                    2, 33, 26, 12, 97, 18, 65, 35, 15, 80, 96, 98, 22, 13, 92, 75, 16, 69, 7, 46, 
                    1, 71, 64, 55, 20, 11, 86, 27, 73, 94, 44, 87, 37, 8, 74, 38, 81, 95, 63, 85, 
                    54, 40, 42, 48, 62, 32, 88, 29, 82, 43, 76, 52, 4, 50, 59, 31, 28, 17, 100, 24 };
 */

int data[1000000] = {0, };
int rear;

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quicksort(int left, int right) {
    int pivot = left;
    int j = pivot;
    int i = left+1;

    if(left < right) {
        for(; i< right; i++) {
            if(data[i] < data[pivot]) {
                j++;
                swap(&data[j], &data[i]);
            }
        }
        swap(&data[left], &data[i]);
        pivot = j;

        for(int i=0; i<rear; i++) {
        printf("%d ", data[i]);
        }
        printf("\n");

        quicksort(left, pivot-1);
        quicksort(pivot+1, right);
    }
}

int main() {
    scanf("%d", &rear);
    for(int i=0; i<rear; i++) {
        scanf("%d", &data[i]);
    }
    for(int i=0; i<rear; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    quicksort(0,rear-1);
    for(int i=0; i<rear; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    return 0;
}