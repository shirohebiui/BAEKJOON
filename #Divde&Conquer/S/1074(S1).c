#include <stdio.h>
int n, r, c;
int cnt;
void conquer(int mid) {
    if(mid == 0) return;
    mid = mid>>1;
    // printf("%d %d mid %2d ", r, c, mid);
    if(r<mid && c<mid) {
        //cnt += 0;
    } else if(r<mid && c>=mid) {
        cnt += mid*mid;
        c -= mid;
    } else if(r>=mid && c<mid) {
        cnt += mid*mid*2;
        r -= mid;
    } else {
        cnt += mid*mid*3;
        r -= mid; c -= mid;
    }
    // printf("cnt %2d\n", cnt);
    conquer(mid);
}

int main() {
    scanf("%d %d %d", &n, &r, &c);
    conquer(1<<n);
    printf("%d\n", cnt);
    return 0;
}