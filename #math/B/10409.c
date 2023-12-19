#include <stdio.h>

int main() {
    int TestCase, mytime; scanf("%d %d", &TestCase, &mytime);
    for(int i=0; i<TestCase; i++) {
        int cost; scanf("%d", &cost);
        mytime -= cost;
        if(mytime < 0){
            printf("%d\n", i);
            return 0;
        }
    }
    printf("%d\n", TestCase);
    return 0;
}