#include <stdio.h>
#include <string.h>

double arr[1000];
double stack[1000]; int top;

double pop() {
    return stack[--top];
}

void push(double op) {
    stack[top++] = op;
}

int main() {
    int op_cnt; scanf("%d", &op_cnt);
    char text[101*26]; scanf("%s", text);
    for(int i=0; i<op_cnt; i++) {
        scanf(" %lf", &arr[i]);
    }
    
    double op1, op2, result;
    for(int i=0; i<strlen(text); i++) {
        switch (text[i])
        {
        case '+':
            op2 = pop();
            op1 = pop();
            push(op1 + op2);
            break;
        case '-':
            op2 = pop();
            op1 = pop();
            push(op1 - op2);
            break;
        case '*':
            op2 = pop();
            op1 = pop();
            push(op1 * op2);
            break;
        case '/':
            op2 = pop();
            op1 = pop();
            push(op1 / op2);
            break;
        default:
            stack[top++] = arr[text[i]-'A'];
            break;
        }
    }
    printf("%.2f\n", stack[0]);
	return 0;
}