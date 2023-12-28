#include <stdio.h>

int main() {
    char str[100][101]; int line = 0;
    while(scanf(" %[^\n]s", str[line++]) != EOF) {
        printf("%s\n", str[line-1]);
    }
    return 0;
}