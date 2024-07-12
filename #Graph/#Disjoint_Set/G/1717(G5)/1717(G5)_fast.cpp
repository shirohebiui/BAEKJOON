#include <cstdio>
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

constexpr int R_SZ = 1<<19;
char *bp, buf[R_SZ];

inline char ReadChar() {
    if(bp == buf+R_SZ) fread(bp = buf, sizeof(char), R_SZ, stdin);
    return *bp++;
}
inline int ReadInt() {
    int ret = 0;
    for (char c = ReadChar(); c&16; ret = (ret<<1) + (ret<<3) + (c&15), c = ReadChar());
    return ret;
}
constexpr int W_SZ = 1<<19;
char wbuf[W_SZ]; int wp, wp_end = W_SZ-5;

inline void wb_flush() {
    fwrite(wbuf, 1, wp, stdout);
    wp = 0;
}

inline void wbwrite(bool flag) {
    if(flag) {wbuf[wp++] = 'Y'; wbuf[wp++] = 'E'; wbuf[wp++] = 'S'; wbuf[wp++] = '\n';}
    else {wbuf[wp++] = 'N'; wbuf[wp++] = 'O'; wbuf[wp++] = '\n';}

    if(wp > wp_end) wb_flush();
}

inline void init(int n);
#define MAX_VSIZE 1000001
int parent[MAX_VSIZE];
inline int find(int x);
void _union(int a, int b);


int main() {
    fread(bp = buf, sizeof(char), R_SZ, stdin);
    int n = ReadInt(), m = ReadInt();
    init(n);
    int mod, A, B;
    while(m-->0) {
        // 0 a b -> a, b집합 합치기
        // 1 a b -> a, b같은 집합인지 확인하고 **같은 집합이면 YES, 아니면 NO 출력**
        // scanf(" %d %d %d", &mod, &A, &B);
        mod = ReadInt(); A = ReadInt(); B = ReadInt();
        if(mod) {
            wbwrite(find(A) == find(B));
        } else {
            _union(A, B);
        }
    }
    wb_flush();
    return 0;
}

void init(int n) {
    FOR(i, 1, n+1) parent[i] = i;
}

int find(int x) {
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void _union(int a, int b) {
    a = find(a);
    b = find(b);
    if(a > b) parent[a] = b;
    else parent[b] = a;
}