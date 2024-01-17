#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define min(a,b) (a<b?a:b)

char ori[11]; int len, gap;
char crash[10];
int std;

char push[11];
int tmp;
int best[3] = {9999999,9999999,9999999};
int c;
void dfs(int cnt, int M) {
    if(cnt == M) {
        int sp = 1;
        tmp = 0;
        while(cnt--) {
            tmp += push[cnt] * sp; sp *= 10;
        }
        if(abs(std-tmp) < abs(std-best[c])) {
            best[c] = tmp;
            // printf("tmp %d\n", tmp);
        }
        return;
    }
    for(int i=0; i<10; i++) {
        if(!crash[i]) {
            push[cnt] = i;
            dfs(cnt+1, M);
        }
    }
}

void input();
void init();

int main() {
    input();
    init();

    // printf("len %d\n", len);
    // -1, 0, +1
    c=0;
    dfs(0,len+1); //자릿수 하나추가
    best[c] = abs(std - best[c]) + len+1;
            // printf("best[%d] %d\n",c, best[c]);
    c=1;
    dfs(0,len); //자릿수 동일
    best[c] = abs(std - best[c]) + len;
            // printf("best[%d] %d\n",c, best[c]);
    if(len > 1) {
    c=2;
    push[0] = 0; dfs(1,len); //자릿수 하나 빼기, 버튼0이 고장나도 맨앞에 0은 가능한 경우
    best[c] = abs(std - best[c]) + len-1;
            // printf("best[%d] %d\n",c, best[c]);
    }

    int result = gap;
    for(int i=0; i<3; i++) {
            // printf("best[%d] %d\n",i, best[i]);
        result = min(result, best[i]);
    }
    printf("%d\n", result);
}

void input() {
    //input
    scanf("%s", ori);
    int m; scanf(" %d", &m);
    while(m--) {
        int no; scanf(" %d", &no);
        crash[no] = 1;
    }
}
void init() {
    len = strlen(ori);
    int k = len; int sp = 1;
    while(k--) {
        ori[k] -= '0';
        std += ori[k] * sp;
        sp *= 10;
    }
    gap = abs(std - 100);
}