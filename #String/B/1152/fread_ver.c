#include <stdio.h>
char buf[1000001];
int main() {
    int word=1;
    fread(buf, sizeof(char), 1000000, stdin);
    char *ptr=buf+1;
    while(*ptr != '\0') {
        if(*ptr++ == ' ') word++;
    }
    if(*(ptr-1) == ' ') word--;
    else if(*(ptr-1) == '\n' && *(ptr-2) == ' ') word--;
    printf("%d\n", word);
    return 0;
}