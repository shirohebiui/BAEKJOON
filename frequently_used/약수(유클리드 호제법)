#include <stdio.h>
/*
https://www.acmicpc.net/problem/1735
유클리드 호제법
*/

int gcd(int a, int b)
{
    int tmp;
	while(b)
	{
		tmp = a % b;
		a = b;
		b = tmp;
	}
    return a;
}

int main()
{
    //printf("echo\n");
    int A1, B1, A2, B2;
    scanf("%d%d %d%d", &A1, &B1, &A2, &B2);
    int N=1;
    long top = A1*B2 + B1*A2;
    long btm = B1*B2;
    long a, b;

    //a, b에 내림차순대입 (유클리드 호제법에 대입할때 a>b여야함)
    if(top>btm) {
        a=top, b=btm;
    } else {
        a=btm, b=top;
    }

    //유클리드 호제법을 사용해 변수에 공약수를 저장
    long tmp = gcd(a, b);

    //유클리드 호제법으로 구한 공약수를 사용해 나누기
    printf("%ld %ld\n", top/tmp, btm/tmp);
    return 0;
}