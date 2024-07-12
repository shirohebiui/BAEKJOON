using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

#include <cstdio>
int n;
long mem[90][2];

int main() {
    scanf("%d", &n);
    mem[0][0] = 0;
    mem[0][1] = 1;
    FOR(i, 1, n) {
        mem[i][0] = mem[i-1][1] + mem[i-1][0];
        mem[i][1] = mem[i-1][0];
    }
    printf("%ld\n", mem[n-1][1] + mem[n-1][0]);
    return 0;
}