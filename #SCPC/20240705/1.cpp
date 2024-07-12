#include <cstdio>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)
int ans;

char buf[300001];
int main(int argc, char** argv)
{
    buf[0] = buf[1] = 'B';
    setbuf(stdout, NULL);
	int Tsize; scanf("%d", &Tsize);
    FOR(test_case, 0, Tsize) {
        ans = 0;

        int n; scanf("%d ", &n);
        // fread(buf+2, sizeof(char), n, stdin); //<실화 이거하나떄문에? 설명을 잘 읽어보자 멍청아
        scanf("%s", buf+2);
        char *p = buf+2;
        while(*p != '\0') {
            if(*p == 'A') {
                if(*(p-1) == 'A') ans+=2;
                else if(*(p-2) == 'A') ans++;
            }
            p++;
        }
        //answer
        printf("Case #%d\n", test_case+1);
        printf("%d\n", ans); fflush(stdout);
	}
	return 0;
}