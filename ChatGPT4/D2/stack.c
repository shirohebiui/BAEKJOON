#include <stdio.h>
#include <stdlib.h>
int top = 0;
int arr[10] = {0, };
void push(int data) {
    arr[top] = data;
    top++;
}

int pop() {
    int tmp = arr[top-1];
    top--;
    return tmp;
}

int empty() {
    if(top == 0) {
        fprintf(stderr, "error : empty!\n");
        exit(1);
    }
    //printf("array is not empty\n");
    return 0;
} 

int peek() {
    empty();

    return arr[top];
}

int main() {
    push(10);
    push(20);
    printf("%d %d %d\n", arr[0], arr[1], arr[2]);
    printf("pop : %d\n", pop());
    push(30);
    printf("%d %d %d\n", arr[0], arr[1], arr[2]);
    printf("pop : %d\n", pop());
    pop();
    push(1);
    int tmp = peek();
    printf("%d\n", tmp);
    return 0;
}