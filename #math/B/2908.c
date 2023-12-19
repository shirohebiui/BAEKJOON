#include <stdio.h>
#include <string.h>

int main() {
    char s1[4], s2[4];
    scanf("%s %s", s1, s2);
    char tmp = s1[0];
    s1[0] = s1[2];
    s1[2] = tmp;
    tmp = s2[0];
    s2[0] = s2[2];
    s2[2] = tmp;
    if(strcmp(s1, s2) > 0)
        printf("%s\n", s1);
    else
        printf("%s\n", s2);
    return 0;
}