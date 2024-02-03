#include <stdio.h>
#include <string.h>
char sp[101]; int len, N;

static inline int isNum(char *sp, int len) {
    int exp = 1;
    int res = 0;
    while(len--) {
        res += (sp[len]-'0')*exp; exp *= 10;
    }
    return res;
}

static inline void findDiv(int n) {
    for(int i=2; i*i<=n; i++) if(n%i == 0) {
        printf("%d %d\n", n, i);
        N--;
        return;
    }
}

static inline void isDiv() {
    int mod = 0;
    //3의 배수
    for(int i=0; i<len; i++) {
        mod *= 10;
        mod += sp[i] - '0';
        mod %= 3;
    }
    if(mod == 0) {
        printf("%s 3\n", sp);
        N--;
        return;
    }
}



int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        //input
        scanf(" %d %s", &N, sp);
        len = strlen(sp);
        
        //anwer
        for(int k=0; k<len; k++) {
            int origin = sp[k];
            for(int q= k==0 ? 1 : 0; q<10; q++) {
                if(q == origin) continue;
                sp[k] = q + '0';

                if(len < 8) findDiv(isNum(sp, len));
                else isDiv();
                if(N == 0) goto out;
            }
            sp[k] = origin;
        }
        out:
    }
    return 0;
}