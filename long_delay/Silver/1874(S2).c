#include <stdio.h>
#define MAX 100000
int stack[MAX] = {0, };
int sign[MAX*2] = {0, };
int rear = 0, p = 0;


void push(int k) {
    stack[rear++] = k;
}

int pop() {
    if(rear >= 0) {
        return stack[rear--];
    }
    return 0;
}

int main() {
    int round;
    scanf("%d", &round);

    int input;
    int n = 1;
    int flag = 0;
    while(round--) {
        scanf("%d", &input);
        if(n <= input) {
            while(n <= input)
            {
                //printf("push\n");
                sign[p++]++;
                push(n++);
            }
        }
        if(stack[rear-1] == input) {
            //printf("pop\n");
            p++;
            pop();
        } else {
            flag = 1;
        }
    }
    if(flag) {
        printf("NO\n");
        return 0;
    }
    for(int i=0; i<p; i++) {
        if(sign[i] == 1) {
            printf("+\n");
        } else {
            printf("-\n");
        }
    }
    return 0;
}