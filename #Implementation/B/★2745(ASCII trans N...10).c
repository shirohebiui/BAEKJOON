#include <stdio.h>
#include <string.h>
/*
input : B진법 N
1line : N,B
최대치 10억 -> long을 써야겠다 백준은 int가 2바이트다
output : B진법 N을 10진수로 출력

문자열을 숫자열로 바꾸는 함수는 atoi라는게 있다고한다.
하지만 어...안썻다.
아스키코드표를 보고 1과 A의 시작값을 확인후 뺄셈을통해 1이면 1 A면 10이 되도록 맞춰서
pow함수를 구현한뒤 진법연산을 구현하여 해결했다.
*/
char alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
int find(char c)
{
    for(int i=0;i<26;i++)
    {
        if(c == alpha[i])
        {
            return i+11;
        }
    }
}

int pow_(int base, int power)
{
    int result=base;
    if(power == 0)
        return 1;
    for(int i=0;i<power-1;i++)
        result *=base;
    return result;
}
int main()
{
    int B;
    char N[31];//2진법이 10억이 될경우 30글자라고 챗gpt가 알려줌
    scanf("%s%d",N, &B);
    int max = strlen(N);
    long tmp=1;
    long sum=0;
    int count=0;
    //printf("%s %d\n", N, B);
    for(int i=max-1;i>-1;i--)
    {
        //문자 1은 49 , A는 65
        if(N[i]<64)
        {
            //printf("[%d] %d pow:%d\n",i, N[i]-48, pow_(B, count));
            sum += (N[i]-48)*pow_(B, count++);
        }
        else
        {
            //printf("[%d] %d pow:%d\n",i, N[i]-55, pow_(B, count));
            sum += (N[i]-55)*pow_(B, count++);
        }
    }
    printf("%ld\n", sum);
    return 0;
}