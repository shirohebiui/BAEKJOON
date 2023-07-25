#include <stdio.h>

int main() {
    int h=5;
    int i, j;
    for(i=0; i<h; i++) {
        for(j=h;j>i;j--) {
            printf(" ");
        }
        for(j=0;j<i*2+1;j++) {
            printf("*");
        }
        printf("\n");
    }
    for(i=h; i>=0; i--) {
        for(j=h;j>i;j--) {
            printf(" ");
        }
        for(j=0;j<i*2+1;j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}