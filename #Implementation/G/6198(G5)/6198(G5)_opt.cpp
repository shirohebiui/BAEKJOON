#include <cstdio>
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

constexpr int SZ = 1<<14;
char *bp, buf[SZ];

inline char ReadChar() {
    if(bp == buf+SZ) fread(bp = buf, sizeof(char), SZ, stdin);
    return *bp++;
}
inline int ReadInt() {
    int ret = 0;
    for (char c = ReadChar(); c&16; ret = (ret<<1) + (ret<<3) + (c&15), c = ReadChar());
    return ret;
}

int H[80000], n;
long long ans;

inline int view_cnt(int idx) {
    int cnt = 0, tmp;
    FOR(i, idx+1, n) {
        if(H[i] >= H[idx]) break;
        tmp = view_cnt(i);
        cnt += tmp+1;
        i += tmp;
    }
    ans += cnt;
    return cnt;
}

int main() {
    //input
    fread(bp = buf, sizeof(char), SZ, stdin);
    n = ReadInt();
    FOR(i, 0, n) H[i] = ReadInt();

    //func
    FOR(i, 0, n) {
        i += view_cnt(i);
    }
    printf("%lld\n", ans);
	return 0;
}