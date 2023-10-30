#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char str[100000];
int is_valid_bracket() {
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
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%s", str);
        if(is_valid_bracket()) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}