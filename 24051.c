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
    int MAX, K;
    scanf("%d%d", &MAX, &K);

    input_data(MAX);
    
    int i = 0, j, cnt=1, last_pt;
    for(i=1; i<MAX; i++) {
        int flag = 0;
        for(j=i; j>0; j--) {
            //printf("%d %d %d\n", i, j, j-1);
            if(arr[j]<arr[j-1]) {
                if(!flag)
                    flag = 1;
                int tmp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = tmp;
                if(cnt++ == K) {
                    printf("%d\n",arr[j]);
                    return 1;
                }
                last_pt = j-1;
            }
        }
        if(flag && cnt++ == K) {
            printf("%d\n",arr[last_pt]);
            return 1;
        }
    }
    printf("-1\n");
    //print_all(MAX);
    return 0;
}
/* 
5 8
4 5 1 3 2 
*/