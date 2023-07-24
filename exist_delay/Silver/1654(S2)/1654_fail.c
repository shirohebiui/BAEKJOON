#include <stdio.h>
#include <stdlib.h>

int main()
{
    long base, need;
    scanf("%ld%ld", &base, &need);

    long arr[10001];
    long long max = 0;
    long min = 1000000;
    for(int i=0; i<base; i++) {
        scanf("%ld", &arr[i]);
        max+=arr[i];
        if(min>arr[i])
            min =arr[i];
    }
    max /= need;
    min /= need;

    long max_length=0;
    long long sum=0;
    for(long long i=max; i>=min; i--) {
        sum = 0;
        for(int j=0; j<base; j++) {
            sum += arr[j]/i;
        }
        if(sum>=need) {
            printf("%lld\n", i);
            return 0;
        }
    }
    return 0;
}