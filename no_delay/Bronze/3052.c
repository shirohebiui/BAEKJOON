#include <stdio.h>

int main()
{
    int N;
    int count[1001]= {0, };
    for(int i=0; i<10; i++) {
        scanf("%d", &N);
        count[N%42]++;
    }
    int tmp=0;
    for(int i=0; i<1001; i++) {
        if(count[i])
            tmp++;
    }
    printf("%d\n", tmp);
    return 0;
}