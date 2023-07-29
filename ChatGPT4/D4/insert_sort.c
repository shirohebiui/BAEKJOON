#include <stdio.h>

int arr[1000];

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void print_all(int MAX) {
    for(int i=0; i<MAX; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void input_data(int MAX) {
    int i=0;
    while(i < MAX) {
        scanf("%d", &arr[i++]);
    }
}
int main() {
    int MAX;
    scanf("%d", &MAX);

    input_data(MAX);
    
    int i = 0, j;
    for(i=1; i<MAX; i++) {
        for(j=i; j>0; j--) {
            //printf("%d %d %d\n", i, j, j-1);
            if(arr[j]<arr[j-1]) {
                int tmp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = tmp;
            }
        }
    }
    print_all(MAX);
    return 0;
}