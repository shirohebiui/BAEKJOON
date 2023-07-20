#include <stdio.h>
/*
문자길이가 80이면 널포인터를 넣을수잇게 81까지!
*/
int main()
{
    char ox[81];
    char *start = ox;
    char *ptr;
    int test, prev, now, score;
    scanf("%d", &test);
    while(test--) {
        ptr = start;
        scanf("%s", ox);
        score = 0; prev = 0;
        while(*ptr != NULL) {
            if(*ptr++ == 'O') {
                now = prev+1;
            } else {
                now = 0;
            }
            score += now;
            prev = now;
        }
        printf("%d\n", score);
    }
    return 0;
}