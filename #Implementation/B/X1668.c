#include <stdio.h>

int main() {
    int N; scanf("%d", &N);
    int arr[50];
    for(int i=0; i<N; i++) {
        scanf("%d", &arr[i]);
    }

    //left
    int high = 0;
    int look = 0;
    for(int i=0; i<N; i++) {
        if(arr[i] > high) {
            high = arr[i];
            look++;
        }
    }
    printf("%d\n", look);
    //right
    high = 0;
    look = 0;
    for(int i=N-1; i>=0; i--) {
        if(arr[i] > high) {
            high = arr[i];
            look++;
        }
    }
    printf("%d\n", look);
    return 0;
}