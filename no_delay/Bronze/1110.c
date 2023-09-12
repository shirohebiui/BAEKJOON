#include <stdio.h>

int add_cycle(int val, int origin, int cycle) {
    int ten = val%10;
    int one = (val/10 + val%10)%10;
    //printf("%d%d\n", ten, one);
    if(ten*10 + one == origin) {
        printf("%d\n", cycle);
    } else {
        add_cycle(ten*10 + one, origin, cycle+1);
    }
    return 0;
}

int main() {
    int N;
    scanf("%d", &N);

    add_cycle(N, N, 1);
    return 0;
}