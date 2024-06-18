#include <stdio.h>
#include <string.h>

/*
이미 배웠던 알고리즘 문제
*/

int base[1001][1001] = {0, };

int main() {
    char base_str[1001];
    scanf("%s", base_str);
    
    char cmp_str[1001];
    scanf("%s", cmp_str);

    int base_len = strlen(base_str);
    int cmp_len = strlen(cmp_str);

    for(int i=1; i<=cmp_len; i++) {
        for(int j=1; j<=base_len; j++) {
            if(cmp_str[i-1] == base_str[j-1]) {
                base[i][j] = base[i-1][j-1] + 1;
            } else {
                base[i][j] = base[i-1][j] > base[i][j-1] ? base[i-1][j] : base[i][j-1];
            }
        }
    }
    
    /* for(int i=0; i<=cmp_len; i++) {
        for(int j=0; j<=base_len; j++) {
            printf("%d ", base[i][j]);
        }
        printf("\n");
    } */
    printf("%d\n", base[cmp_len][base_len]);
    return 0;
}