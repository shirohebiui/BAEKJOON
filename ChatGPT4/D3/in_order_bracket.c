#include <stdio.h>
#include <stdbool.h>

char str[10000];
//a 대괄호, b 중괄호, c 소괄호
int a=0, b=0, c=0;

int is_valid(char *str) {
    char *ptr = str;
    while(*ptr != '\0') {
        //대괄호는 중,소괄호 밖에있다.
        if(*ptr == '[') {
            if(a>=0 && b==0 && c==0)
                a++;
            else
                return false;
        }
        else if(*ptr == ']') {
            if(b==0 && c==0 && a>0)
                a--;
            else
                return false;
        }

        //중괄호는 소괄호 밖에있다.
        if(*ptr == '{') {
            if(a>=0 && b>=0 && c==0)
                b++;
            else
                return false;
        } else if(*ptr == '}') {
            if(a>=0 && c==0 && b>0)
                b--;
            else
                return false;
        }

        //소괄호
        if(*ptr == '(') {
            if(a>=0 && b>=0 && c>=0)
                c++;
            else
                return false;
        } else if(*ptr == ')') {
            if(a>=0 && b>=0 && c>0)
                c--;
            else
                return false;
        }
        ptr++; //next
    }
    if(a==0 && b==0 && c==0) {
        return true;
    } else {
        return false;
    }
}
int main() {
    scanf("%s", str);
    if(is_valid(str)) {
        printf("TRUE\n");
    } else {
        printf("FALSE\n");
    }
    return 0;
}