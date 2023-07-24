#include <stdio.h>
/*
https://www.acmicpc.net/problem/4673
양의정수n에 대해 d(n)을 n과 n의 각 자리수를 더하는 함수.
d(33) = 33+3+3 = 39
d(39) = 39+3+9 = 51
...loop
n = 생성자
생성자가 없는 숫자 = 셀프넘버
ex) 100under -> 13개 1 3 5 7 9 20 31 42 53 64 75 86 97

*/

int arr[10001]= {0, };

void self_func(int k) {
    int sum = k;
    while(k>0) {
        sum += k%10;
        k/=10;
    }
    if(sum < 10001) {
        arr[sum] = 1;
    }
}
int main()
{
    int tmp=1;
    for(int i=0; i<10001;i++) {
        self_func(i);
    }
    for(int i=1; i<10001;i++) {
        if(arr[i] == 0)
            printf("%d\n", i);
        //printf("%d\n", arr[i]);
    }
    return 0;
}