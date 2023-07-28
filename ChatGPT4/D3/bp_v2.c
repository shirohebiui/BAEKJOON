#include <stdio.h>
#include <stdbool.h>
#define MAX 100

const char str[MAX]="(((())))))";
int top = 0;

int push_is_valid() {
    if(top<MAX-1)
        return true;
    return false;
}
int pop_is_valid() {
    if(top>0)
        return true;
    return false;
}

void push(char *arr, char data) {
    if(push_is_valid) 
        arr[top++] = data;
}

char pop(char *arr) {
    if(pop_is_valid) {
        int out = arr[--top];
        return out;
    } else {
        return false;
    }
}

char peek(char *arr) {
    return arr[top];
}

int main() {
    char arr[MAX];
    push(arr, ')');
    printf("%c", peek(arr));
    return 0;
}