#include <stdio.h>

int count_two(int k) {
    if(k%2 == 0 && k>0) {
        return 1 + count_two(k/2);
    }
    return 0;
}

int count_five(int k) {
    if(k%5 == 0 && k>0) {
        return 1 + count_five(k/5);
    }
    return 0;
}

int main() {
    int N;
    scanf("%d", &N);

    int five = 0, two = 0;

    for(int i=1; i<=N; i++) {
        two += count_two(i);
        five += count_five(i);
        //printf("%2d : %d %d\n", i, count_two(i), count_five(i));
    }
    int sum = five>two ? two : five;
    
    printf("%d\n", sum);
    return 0;
}