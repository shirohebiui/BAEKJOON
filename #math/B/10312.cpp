#include <cstdio>
#define FOR(val, s, e) for(int val=(s); val<(e); val++)

//READ
constexpr int RSZ = 1<<6;
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
constexpr int WSZ = 1<<6;
char wbuf[WSZ]; int wbp;
const int wbp_end = WSZ - 30;

inline void wbuf_flush() {
    fwrite(wbuf, 1, wbp, stdout);
    wbp = 0;
}

void f(int w) {
    int tmp = 1;
    while(tmp <= w) tmp *= 3;
    while(w) {
        tmp/=3;
        wbuf[wbp] = '0';
        while(tmp <= w) {
            w -= tmp;
            wbuf[wbp]++;
        }
        wbuf[(++wbp)++] = ' ';
    }
    tmp /= 3;
    while(tmp) {
        tmp /= 3;
        wbuf[wbp++] = '0';
        wbuf[wbp++] = ' ';
    }
    wbuf[wbp-1] = '\n';
    if(wbp > wbp_end) wbuf_flush();
}


int main() {
    fread(rbp = rbuf, sizeof(char), RSZ, stdin);
    int tc = ReadInt();
    while(tc--) {
        f(ReadInt());
    }
    wbuf_flush();
    return 0;
}
