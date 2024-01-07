#include <stdio.h>
int lv[31];

int main() {
    int TestCase; scanf(" %d", &TestCase);
    if(!TestCase) goto end;
    int gap = ((double)TestCase * 0.15 + 0.5);
    for(int i=0; i<TestCase; i++) {
        int opinion; scanf(" %d", &opinion);
        lv[opinion]++;
    }
    int tmp = gap; int hi = 30;
    while(tmp) {
        if(lv[hi]) {
            lv[hi]--;tmp--;
        } else hi--;
    }
    tmp = gap; int lo = 1;
    while(tmp) {
        if(lv[lo]) {
            lv[lo]--;tmp--;
        } else lo++;
    }
    int sum = 0;
    for(int i=1; i<31; i++) {
        sum += i * lv[i];
    }
    printf("%d\n", (int)((float)sum/(TestCase-gap-gap)+0.5));
    return 0;
    end:
    printf("0\n");
    return 0;
}