#include <stdio.h>

int stack[500001];

void init_stack(int rear) {
    for(int i=1; i<=rear; i++) {
        stack[i] = i;
    }
}
int main() {
    int N; // 1~N card
    scanf(" %d", &N);
    int rear = N;
    int next_rear;
    init_stack(rear);

    while(rear > 1) {
        next_rear = 0;
        int i;
        for(i=1; i*2<=rear; i++) {
            stack[i] = stack[i*2];
            //printf("%d : %d\n", i, stack[i]);
            next_rear++;
        }
        if(rear%2 == 1) {
            stack[0] = stack[1];
            for(i=1; i<=next_rear; i++) {
                stack[i] = stack[i+1];
            }
            stack[next_rear] = stack[0];
        }
        rear = next_rear;
        /* for(int i=1; i<=rear; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n"); */
    }

    printf("%d\n", stack[1]);
    return 0;
}