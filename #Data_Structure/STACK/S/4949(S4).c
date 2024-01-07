#include <stdio.h>
char stack[101], top;
int push() {
    return stack[--top];
}

int main() {
    char str[101];
    while (1) {
        scanf("%[^\n]s", str);
        getchar();
        if(str[0] == '.') break;
        top = 0;
        char *ptr = str;
        while(*ptr != '\0') {
            if(*ptr == '(' || *ptr == '[') stack[top++] = *ptr;
            else {
                if(*ptr == ')' && push() != '(') {
                    break;
                } else if(*ptr == ']' && push() != '[') {
                    break;
                }
            }
            ptr++;
        }
        if(*ptr != '\0' || top != 0) printf("no\n");
        else printf("yes\n");
    }
    return 0;
}