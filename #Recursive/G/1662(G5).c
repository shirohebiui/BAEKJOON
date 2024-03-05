#include <stdio.h>

char *p;
int func(int mul) {
    if(*p == '(') p++;
    int std = 0;
    while(*p != '\0' && *p != ')') {
        if(*(p+1) == '(') {
            std += func(*p++-'0');
            p++;
        } else {
            std++;
            p++;
        }
    }
    return std*mul;
}

char str[50];
int main() {
    p = str;
    int sum = 0;
    while(*p != '\0') {
        sum += func(1);
        p++;
    }
    printf("%d\n", sum);
    return 0;
}