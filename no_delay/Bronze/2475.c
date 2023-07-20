#include <stdio.h>
/*
6자리 고유번호
처음 5자리 0~99999, 6번째 = 검증수
검증수 = 각수 제곱수의 합의 mod10
*/

int square(int k) {
    return k*k;
}

int main()
{
    //printf("echo\n");
    int pw[6];
    long sum = 0;
    for(int i=0; i<5;i++) {
        scanf("%d", &pw[i]);
        sum += square(pw[i]);
    }
    printf("%ld\n", sum%10);

    return 0;
}