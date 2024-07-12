#include <cstdio>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

constexpr int SZ = 1<<19;
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

int view_cnt(int idx) {
    int cnt = 0, tmp;
    FOR(i, idx+1, n) {
        if(H[i] >= H[idx]) break;
        tmp = view_cnt(i);
        cnt += tmp+1;
        i += tmp;
    }
    ans += cnt;
    // printf("h%d start%d cnt%d ans%d\n", high, idx, cnt, ans);
    return cnt;
}

/*
func(현재 아파트 idx) {
    현재 아파트 높이 = idx번째 아파트 높이;
    현재 아파트에서 볼수있는 아파트갯수 = 0;
    FOR(i=idx; i->n) {
        if(idx번째 아파트높이 >= 현재아파트 높이) break;
        tmp = func(i번째 아파트); //i번째 아파트에서 볼수있는 아파트갯수 반환
        i += tmp;
        현재 아파트에서 볼수있는 아파트갯수 += tmp + 1;
    }
    ans += 현재 아파트에서 볼수있는 아파트갯수;
    return 현재 아파트에서 볼수있는 아파트갯수;
}
*/

int main() {
    //input
    fread(buf, sizeof(char), SZ, stdin); bp = buf;
    n = ReadInt();
    FOR(i, 0, n) H[i] = ReadInt();

    //func
    FOR(i, 0, n) {
        i += view_cnt(i);
    }
    printf("%lld\n", ans);
	return 0;
}