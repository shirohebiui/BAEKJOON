#include <stdio.h>
#include <string.h>
#define PRIME 5381
int n, m;
char name[100000][21];
int sp[100000];
int hash(char *s) {
    char *c = s;
    int p = PRIME;
    int mod = 100000;

    int hash_val = 0;
    int pow_p = 1;

    while(*c != '\0') {
        hash_val += (*c - 0x40) * p; //대문자0x60 소문자0x40
        hash_val %= mod;
        p *= PRIME; p %= mod;
        c++;
    }
    return hash_val;
}

void input() {
    scanf(" %d %d", &n, &m);
    for(int i=0; i<n; i++) {
        scanf("%s", &name[i][0]);
        int key = hash(&name[i][0]);
        while(sp[key] != 0) {
            key++;
            if(key >= 100000) key = 0;
        }
        sp[key] = i;
    }
}

void solve() {
    char pb[21];
    while(m--) {
        memset(pb, 0x00, 21);
        scanf("%s", pb);
        if(pb[0] < 0x40) { //숫자
            char *t = pb;
            while(*t != '\0') t++;
            t--;

            int num = 0;
            int d = 1;
            while(t != pb) {
                num += (*t-- -'0')*d; d*=10;
            }
            num += (*t -'0')*d;
            printf("%s\n", name[num-1]);
        } else {
            int key = hash(&pb[0]);
            while(strcmp(name[sp[key]], pb) != 0) {
                key++;
                if(key >= 100000) key = 0;
            }
            printf("%d\n", sp[key]+1);
        }
    }
}


int main() {
    input();
    solve();
    return 0;
}