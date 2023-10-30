#include <stdio.h>

int count_of_cal = 0;
int find_count_of_cal(int now, int count) {
    if(now == 1) {
        count_of_cal = count_of_cal > count ? count : count_of_cal;
    } else {
        if(now % 2 == 0 && count < count_of_cal)
            find_count_of_cal(now/2, count+1);
        if(now % 3 == 0 && count < count_of_cal)
            find_count_of_cal(now/3, count+1);
        if(count < count_of_cal)
            find_count_of_cal(now-1, count+1);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    count_of_cal = N;

    find_count_of_cal(N, 0);
    printf("%d\n", count_of_cal);
    return 0;
}