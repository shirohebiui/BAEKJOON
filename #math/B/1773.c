#include <stdio.h>

char boom[2000001];

int main() {
    int N, Time; scanf(" %d %d", &N, &Time);
    int cnt=0;
    for(int i=0; i<N; i++) {
        int delay; scanf(" %d", &delay);
        for(int i=delay; i<=Time; i+=delay) {
            if(boom[i] == 0) cnt++;
            boom[i]=1;
        }
    }
    printf("%d\n", cnt);
    return 0;
}