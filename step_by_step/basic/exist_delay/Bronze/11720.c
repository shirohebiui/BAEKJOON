#include <stdio.h>
/*
처음엔 전체숫자에서 %10을한뒤 그값을 sum에 더하고 전체숫자를 /10하는식의 반복을 생각했다.
하지만 입력가능한 숫자의 크기가 너무커서 다 담을 수 없기에 문자열로 숫자를 받은뒤 아스키코드 0 : 48의 대응을 이용하여
문자-48을해 각 위치의 숫자를 sum에 더하는식으로 해결했다.
문자이동은 null포인터를 만날때까지 반복하는식으로 해결했다.
*/
int main()
{
    int N;
    scanf("%d\n", &N);
    char str[10000];
    char *ptr = str;
    scanf("%s", str);
    int sum=0;
    while(*ptr != NULL)
    {
        sum+=*ptr-48;
        ptr++;
    }
    printf("%d\n", sum);
    return 0;
}