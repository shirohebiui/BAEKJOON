#include <stdio.h>

int coin_value[101] = {0, };
int coin_case = 0;
int method = 0;

int func(int now, int value, int goal) {
    for(int i=0; now + coin_value[value]*i <= goal; i++) {
        if(now + coin_value[value]*i == goal) {
            method++;
        } else if(value+1 < coin_case && now + coin_value[value]*i < goal) {
            func(now+coin_value[value]*i, value+1, goal);
        }
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    coin_case = n;
    while(n--) {
        scanf("%d", &coin_value[n]);
    }
    func(0, 0, k);
    printf("%d\n", method);
    return 0;
}