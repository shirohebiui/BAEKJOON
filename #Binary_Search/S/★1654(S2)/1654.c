#include <stdio.h>

long rear, need;
long arr[10001];

long long cal(long std) {
    long long sum = 0;
    for(int j=0; j<rear; j++) {
        sum += arr[j]/std;
    }
    return sum;
}

int main()
{
    scanf("%ld%ld", &rear, &need);

    long long max_len = 0;
    long long P_MAX = 0;
    for(int i=0; i<rear; i++) {
        scanf("%ld", &arr[i]);
        if(max_len < arr[i])
            max_len = arr[i];
    }

    long long left, mid, right, sum;
    left = 1; right = max_len;
    long long max = 0;

    while(left <= right)
    {
        mid = (left + right)/2;
        sum = cal(mid);

        if(need <= sum && max<mid)
            max = mid;

        if(sum < need) {
            printf("left : %lld right :%lld\n", left, right);
            right = mid - 1;
        } else {
            printf("left : %lld right :%lld\n", left, right);
            left = mid + 1;
        }
    }

    printf("%lld\n", max);
    return 0;
}