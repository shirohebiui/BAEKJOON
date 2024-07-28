#include <cstdio>
//**************************base function start*********************************
//READ
constexpr int RSZ = 1<<18;
char rbuf[RSZ], *rbp;
const char *rbp_end = rbuf + RSZ;
inline char ReadChar() {
    if(rbp == rbp_end) fread(rbp = rbuf, sizeof(char), RSZ, stdin);
    return *rbp++;
}
inline int ReadInt() {
    int ret = 0;
    for (char c = ReadChar(); c&16; ret = ret*10 + (c&15), c = ReadChar());
    return ret;
}

//WRITE
constexpr int WSZ = 1<<19;
char wbuf[WSZ]; int wbp;
//**************************base function end************************************
#include <cstring>
#define FOR(val, s_v, e_v) for(int val=(s_v); val<(e_v); ++val)

#define MAX 2001
int arr[MAX];

char mem[MAX][MAX];

bool dp(int e, int s) {
    if(mem[s][e] != -1) return mem[s][e];
    if(s>=e) return mem[s][e] = (arr[s] == arr[e] ? 1 : 0);
    if(arr[s] != arr[e]) return mem[s][e] = 0;
    return mem[s][e] = dp(e-1, s+1);
}


int main() {
    memset(mem, -1, sizeof(mem));
    fread(rbp = rbuf, sizeof(char), RSZ, stdin);
    int n = ReadInt();
    FOR(i, 1, n+1) arr[i] = ReadInt();
    int m = ReadInt();
    while(m--) {
        wbuf[wbp++] = (dp(ReadInt(), ReadInt()) ? '1' : '0');
        wbuf[wbp++] = '\n';
        if(wbp > WSZ-3) {
            fwrite(wbuf, 1, wbp, stdout);
            wbp = 0;
        }
    }
    fwrite(wbuf, 1, wbp, stdout);
    return 0;
}