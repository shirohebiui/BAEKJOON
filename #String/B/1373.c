#include <stdio.h>
#include <string.h>

char bin[1000001];

int main() {
    scanf("%s", bin);
    int len = strlen(bin);
    int k = len;
    while(k--) bin[k] -= '0';

    int i = 0;

    int s = len%3;
    if(s) {
        int output = 0;
        while(s--) output += bin[i++] * 1<<s;
        printf("%d", output);
    }
    for(;i<len;i+=3) {
        printf("%d", bin[i]*4 + bin[i+1]*2 + bin[i+2]);
    }
    printf("\n");
    return 0;
}