#include <cstdio>
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)
//READ
constexpr int RSZ = 1<<22;
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
constexpr int WSZ = 1<<20;
char wbuf[WSZ]; int wbp;
const int wbp_end = WSZ - 30;

inline void wbuf_flush() {
    fwrite(wbuf, 1, wbp, stdout);
    wbp = 0;
}

int data[10001];

int main() {
    fread(rbp = rbuf, sizeof(char), RSZ, stdin);
    int n = ReadInt();
    FOR(i, 0, n) {
        data[ReadInt()]++;
    }
    char output[6] = {0}, output_tmp[6] = {0}, *tmp, *p;
    FOR(i, 1, 10001) {
        if(data[i] == 0) continue;

        tmp = output_tmp+1;
        int input = i;
        while(input) {
            *tmp++ = '0' + input%10;
            input /= 10;
        } tmp--;
        p = output;
        while(*tmp != '\0') *p++ = *tmp--;
        *p = '\0';

        while(data[i]--) {
            p = output;
            while(*p != '\0') wbuf[wbp++] = *p++;
            wbuf[wbp++] = '\n';
            if(wbp > wbp_end) wbuf_flush();
        }
    }
    wbuf_flush();
    return 0;
}