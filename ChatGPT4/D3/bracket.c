#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int is_valid_bracket(char *str) {
    int valid = 0;
    char *ptr = str;
    while(*ptr != '\0') {
        if(*ptr == '(' && valid>=0)
            valid++;
        else
            valid--;
        if(valid < 0)
            return false;
        ptr++;
    }
    if(valid) {
        return false;
    }
    return true;
}

int main() {
    char str[100000];
    int tmp;
    /* strcpy(str,"((()))");
    tmp = is_valid_bracket(str);
    printf("%d\n", tmp);

    strcpy(str,"()(()))");
    tmp = is_valid_bracket(str);
    printf("%d\n", tmp); */
    scanf("%s", str);
    printf("%d\n", is_valid_bracket(str));
    return 0;
}