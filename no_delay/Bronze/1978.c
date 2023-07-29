#include <stdio.h>
#include <string.h>
#define MAX 1000

int main()
{
    int N;
    scanf("%d", &N);
    int arr[MAX] = {1,1, }; //arr[0], arr[1]은 0,1이 소수가 아니므로 1로 초기화해둠
    //소수걸러내기
    for(int i=2; i<MAX; i++) {
        for(int j=2; j*i<MAX; j++) {
            arr[i*j] = 1;
        }
    }
    
    int cnt = 0;
    while(N--) {
        //입력받기
        int tmp;
        scanf("%d", &tmp);
        if(arr[tmp] == 0)
            cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}