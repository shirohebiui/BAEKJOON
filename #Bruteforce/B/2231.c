#include <stdio.h>

int cal(int x) {
    int result = x;
    while(x) {
        result += x%10;
        x /= 10;
    }
    return result;
}

int main() {
    int input; scanf("%d", &input);
    int cnt = 1;
    while(input / (10*cnt)) cnt++; //자릿수 계산
    int x = input - 9*cnt;
    while(x<input) {
        if(input == cal(x)) {
            printf("%d\n", x);
            return 0;
        }
        x++;
    }
    printf("0\n");
    return 0;
}