#include <stdio.h>
#include <string.h>
#define MAX 1001

void print_entire_map(char *base, char *cmp, int arr[][MAX], int x, int y) {
    printf(" 0  0 ");
    for(int j=0; j<=x; j++)
        printf("%2c ", base[j]);
    printf("\n");

    for(int i=0; i<=y; i++) {
        if(i>0)
            printf("%2c ", cmp[i-1]);
        else
            printf(" 0 ");
        for(int j=0; j<=x; j++) {
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("output : %d\n", arr[y][x]);
}

int main() {
    int arr[MAX][MAX] = {0, };
    char base[MAX], cmp[MAX];
    //printf("base : ");
    scanf("%s", base);
    //printf("cmp : ");
    scanf("%s", cmp);
    int x = strlen(base);
    int y = strlen(cmp);

    for(int i=1; i<=y; i++) {
        for(int j=1; j<=x; j++) {
            if(base[j-1] == cmp[i-1]) {
                arr[i][j] = arr[i-1][j-1] + 1;
            } else {
                arr[i][j] = arr[i-1][j]>arr[i][j-1]?arr[i-1][j]:arr[i][j-1];
            }
        }
    }
    printf("%d\n", arr[y][x]);

    //print_entire_map(base, cmp, arr, x, y);

    char stack[MAX];
    int top=0;
    int i=y, j=x;
    while(i>0 && j>0) {
        if(arr[i][j] == arr[i-1][j-1]) {
            i--; j--;
        } else if(arr[i][j] == arr[i][j-1]) {
            j--;
        } else if(arr[i][j] == arr[i-1][j]) {
            i--;
        } else {
            stack[top++] = base[j-1];
            i--; j--;
        }
    }

    if(arr[y][x] != 0) {
        while(top--) {
            printf("%c", stack[top]);
        }
        printf("\n");
    }
    return 0;
}