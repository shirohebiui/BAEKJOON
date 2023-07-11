#include <stdio.h>
#include <string.h>
/*
input : B진법 N
1line : N,B
이전에 진법으로 써진것을 10진수로 출력하는것의 반대
10진수를 받아 진법으로 변환한다.

pow_함수의 result를 int로 선언해서 10억에 해당하는 값을 받지못하고 세그먼트오류가 떳다
long으로 바꿔 해결
*/
char trans(int k)
{
    char arr[50] ={'0','1','2','3','4','5','6','7','8','9',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    return arr[k];
}
long pow_(int base, int power)
{
    long result=base;
    if(power == 0)
        return 1;
    for(int i=0;i<power-1;i++)
        result *=base;
    return result;
}
int main()
{
    int B;//B진법
    long N;//10진법으로 숫자
    int arr[50]={0};
    scanf("%ld%d",&N, &B);
    int count=0;
    long pow_arr[50]={0};
    while(1)
    {
        pow_arr[count] = pow_(B, count);
        if(N<pow_arr[count])
            break;
        count++;
    }
    //for(int i=count;i>=0;i--) printf("%ld\n", pow_arr[i]);
    for(int i=count;i>0;i--)
    {
        while(pow_arr[i]>N && N>=pow_arr[i-1] && i>1)
        {
            if(N<0)
                break;
            N = N-pow_arr[i-1];
            arr[i]++;
        }
    }
    for(int i=count;i>1;i--)
    {
        printf("%c", trans(arr[i]));
    }
    printf("%c\n", trans(N));
    
    return 0;
}