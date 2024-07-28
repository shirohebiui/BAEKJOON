#include <cstdio>
constexpr int SZ = 1<<16;
int main() {
    char buf[SZ];
    int word=1, bsize;
    char *ptr = buf;

    bsize = fread(buf, sizeof(char), SZ, stdin);
    ptr = buf+1;
    while(1) {
        while(*ptr != '\0') {
            if(*ptr++ == ' ') word++;
        }
        if(ptr < &buf[SZ]) break;
        bsize = fread(buf, sizeof(char), SZ, stdin);
        buf[bsize] = '\0';
        ptr = buf;
    }

    ptr = (ptr-1 >= buf) ? ptr-1 : &buf[SZ-1];
    if(*ptr == ' ') word--;
    else if(*ptr == '\n') {
        ptr = ptr-1 >= buf ? ptr-1 : &buf[SZ-1];
        if(*ptr == ' ') word--;
    }
    printf("%d\n", word);
    return 0;
}