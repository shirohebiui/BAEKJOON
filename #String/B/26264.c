#include <stdio.h>
#include <string.h>

int main() {
    //init
    char *s = "security"; int s_len = strlen(s);
    char *b = "bigdata";  int b_len = strlen(b);

    //input
    int N; scanf("%d", &N);
    char in[8 * 100000]; scanf("%s", in);

    //check s & b
    int cnt = 0;
    char *ptr = in;
    for(int i=0; i<N; i++) {
        if(*ptr == 's') {
            cnt++;
            ptr += s_len;
        } else {
            cnt--;
            ptr += b_len;
        }
    }

    if(cnt > 0) {
        printf("security!\n");
    } else if(cnt == 0) {
        printf("bigdata? security!\n");
    } else {
        printf("bigdata?\n");
    }
    return 0;
}