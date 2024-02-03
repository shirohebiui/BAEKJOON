#include <stdio.h>

int height[500001][2]; int n, h;

void test() {
    for(int i=h; i>=1; i--) {
        printf("%d %d %d\n", height[i][0], height[i][1], height[i][0] + height[i][1]);
    }
    printf("\n");
}


int main() {
    scanf("%d %d", &n, &h);
    for(int i=0; i<n; i++) {
        int d; scanf(" %d", &d);
        if(i%2) {
            height[d][0]++;
        } else {
            height[h-d+1][1]++;
        }
    }
    for(int i=1; i+1<=h; i++) {
        height[i+1][1] += height[i][1];
    }
    for(int i=h; i-1>=1; i--) {
        height[i-1][0] += height[i][0];
    }
    // test();
    int best = 200000;
    int range;
    for(int i=1; i<=h; i++) {
        int wall = height[i][0] + height[i][1];
        if(best > wall) {
            best = wall; range = 1;
            while(i<h && height[i][0] + height[i][1] != best) i++;
        } else if(best == wall) {
            range++;
        }
    }
    printf("%d %d\n", best, range);
    return 0;
}