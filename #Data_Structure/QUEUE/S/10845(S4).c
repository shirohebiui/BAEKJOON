//https://www.acmicpc.net/problem/10845
#include <stdio.h>
#include <string.h>
#define MAX 100000

int rear = 0, front = 0;
int queue[MAX];

void push(int data) {
    queue[rear++ % MAX] = data;
}

int pop() {
    if(front < rear) {
        return queue[front++];
    } else {
        return -1;
    }
}

int IsValid() {
    return rear - front;
}

int empty() {
    if(IsValid() > 0) {
        return 0;
    } {
        return 1;
    }
}

int main() {
    int N;
    scanf("%d", &N);

    while(N--) {
        char cmd[100];
        scanf("%s", cmd);
        if(strcmp(cmd, "push") == 0) {
            int data;
            scanf(" %d", &data);
            push(data);
        } else if(strcmp(cmd, "pop") == 0) {
            printf("%d\n", pop());
        } else if(strcmp(cmd, "size") == 0) {
            printf("%d\n", IsValid());
        } else if(strcmp(cmd, "empty") == 0) {
            printf("%d\n", empty());
        } else if(strcmp(cmd, "front") == 0) {
            if(IsValid())
                printf("%d\n", queue[front]);
            else
                printf("-1\n");
        } else if(strcmp(cmd, "back") == 0) {
            if(IsValid())
                printf("%d\n", queue[rear-1]);
            else
                printf("-1\n");
        }
    }

    return 0;
}