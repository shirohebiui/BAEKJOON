#include <cstdio>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

//READ
constexpr int RSZ = 1<<16;
char rbuf[RSZ], *rbp;
inline char ReadChar() {
    if(rbp == rbuf + RSZ) fread(rbp = rbuf, sizeof(char), RSZ, stdin);
    return *rbp++;
}
inline int ReadInt() {
    int ret = 0;
    for (char c = ReadChar(); c&16; ret = (ret<<1) + (ret<<3) + (c&15), c = ReadChar());
    return ret;
}

//union
#define MAXVSIZE 501
typedef short s16;
s16 vsize, parent[MAXVSIZE]; int esize;
inline void init_() {
	FOR(i, 1, vsize+1) parent[i] = i;
}

inline s16 pfind(s16 x) {
	if(x == parent[x]) return x;
	return parent[x] = pfind(parent[x]);
}

inline void _union(s16 a, s16 b) {
    a = pfind(a); b = pfind(b);
    a > b ? parent[a] = b : parent[b] = a;
}

inline s16 CountOfTree() {
	s16 cnt = 0;
	FOR(i, 1, vsize+1) if(i == parent[i]) cnt++;
	return cnt;
}

int main() {
	fread(rbp = rbuf, sizeof(char), RSZ, stdin);
	parent[MAXVSIZE-1] = MAXVSIZE-1;
	s16 v, u, tree_cnt;
	int case_cnt = 0;
	while(++case_cnt) {
		vsize = ReadInt(); esize = ReadInt();
		if(vsize == 0 && esize == 0) break;
		init_();
		while(esize--) {
			v = ReadInt(); u = ReadInt();
			if(pfind(v) == pfind(u)) {parent[pfind(u)] = 0; continue;}
			_union(v, u);
		}
		tree_cnt = CountOfTree();
		if(tree_cnt == 0) printf("Case %d: No trees.\n", case_cnt);
		else if(tree_cnt == 1) printf("Case %d: There is one tree.\n", case_cnt);
		else printf("Case %d: A forest of %d trees.\n", case_cnt, tree_cnt);
	}
    return 0;
}