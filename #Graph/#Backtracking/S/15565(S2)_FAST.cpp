#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

#include <cstdio>
#include <cstdlib>
#include <cstring>
int n, m;
char str[8][7], *select_s[8];

#define buf_size 1<<20
#define flush_limit 1<<19
char vis[8][8], buf[buf_size]; int b_ptr;

void bwrite(char *p) {
    while(*p != '\0') buf[b_ptr++] = *p++;
    buf[b_ptr++] = ' ';
}

inline void buf_flush() {
    fwrite(buf, 1, b_ptr, stdout);
    b_ptr = 0;
}

void dfs(int depth) {
	if(m == depth) {
		FOR(i, 0, m) bwrite(select_s[i]);
        buf[b_ptr-1] = '\n';
        if(b_ptr >= flush_limit) buf_flush();
		return;
	}
	FOR(i, 0, n) {
		if(vis[depth][i]) continue;
		vis[depth][i] = 1;
		select_s[depth] = str[i];
		dfs(depth+1);
		vis[depth][i] = 0;
	}
}

int cmp(const void *s1, const void *s2) {
    return atoi((const char*)s1) > atoi((const char*)s2);
}
int main() {
    scanf("%d %d", &n, &m);
    FOR(i, 0, n) {
        scanf("%s", str[i]);
        strlen(str[i]);
        FOR(j, 0, n) {
            if(j == i) continue;
            if(strcmp(str[i], str[j]) == 0) {
                i--; n--; break;
            }
        }
    }
    qsort(str, n, sizeof(str[0]), cmp);
	dfs(0);
    buf_flush();
    return 0;
}