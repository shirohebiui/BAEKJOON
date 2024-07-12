#include <cstdio>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

constexpr int SZ = 1<<19;
char *p, buf[SZ];

inline char ReadChar() {
    if(p == buf+SZ) fread(p = buf, sizeof(char), SZ, stdin);
    return *p++;
}
inline int ReadInt() {
    int ret = 0;
    for (char c = ReadChar(); c&16; ret = (ret<<1) + (ret<<3) + (c&15), c = ReadChar());
    return ret;
}

struct node {
    int d_meter, cnt;
};
node v[300000]; int top = 0;

int main() {
    fread(buf, sizeof(char), SZ, stdin); p = buf;
    int d = ReadInt(), n = ReadInt();
    int diameter, height = d;
    v[top] = {1000000001, 1};
    FOR(i, 0, d) {
        diameter = ReadInt();
        if(v[top].d_meter <= diameter) v[top].cnt++;
        else v[++top] = {diameter, 1};
    }
    FOR(i, 0, n) {
        if(top < 0) goto fail;
        diameter = ReadInt();
        while(v[top].d_meter < diameter) {
            height -= v[top].cnt;
            if(--top < 0) goto fail;
        }
        height--;
        if(--v[top].cnt == 0) --top;
    }
    printf("%d\n", height+1);
    return 0;
    fail:
    printf("0\n");
	return 0;
}