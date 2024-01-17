#include <stdio.h>
#include <string.h>

long _pow(int n, int x) {
    long res = 1;
    while(x--) res *= n;
    return res;
}
char str[52];

int main() {
    scanf("%s", str);
    char *ptr = str;
    long sum = 0, mod = 0;
    do {
        if(*(ptr-1) == '-') mod = 1;
        char *s = ptr;

        int idx = 0;
        while(*ptr != '-' && *ptr != '+' && *ptr != '\0') {
            ptr++; idx++;
        }
        int num = 0;
        while(idx--)  num += _pow(10,idx) * (*s - '0'); s++;
        
        if(mod) sum -= num;
        else    sum += num;
        // printf("\nnum: %d sum : %ld\n", num, sum);
        ptr++;
    } while(*ptr != '\0');
    printf("%ld\n", sum);
	return 0;
}