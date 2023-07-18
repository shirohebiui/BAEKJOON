#include <stdio.h>
/*
https://www.acmicpc.net/problem/11653
소인수분해
*/

int find_prime(int prime)
{
    long tmp=2;
    long half = prime/2;
    while(1)
    {
        if(prime == tmp) {
            return 1;
        } else if(prime%tmp != 0) {
            tmp++;
        } else {
            //if(prime%tmp == 0)
            return 0;
        }
    }
}

int main()
{
    long N;
    scanf("%ld", &N);

    long half = N/2;
    long tmp=2;
    long prime[5] ={2, 3, 5, 7, 11};
    int x=1;
    if(N==1){
        return 0;
    }
    else {
        while(N!=1)
        {
        if(N%tmp == 0) {
            N=N/tmp;
            printf("%ld\n",tmp);
        } else {
            int flag = 0;
            while(flag == 0)
            {
                if(tmp < 11)
                {
                    tmp = prime[x++];
                    flag = 1;
                }
                else
                {
                    tmp++;
                    flag = find_prime(tmp);
                }
            }
        }
        }
    }/* else {
        while(N!=1)
        {
        if(N%tmp == 0) {
            N=N/tmp;
            printf("%ld\n",tmp);
        } else {
            int flag = 0;
            while(flag == 0)
            {
                tmp++;
                flag = find_prime(tmp);
            }
        }
        }
    } */
    return 0;
}