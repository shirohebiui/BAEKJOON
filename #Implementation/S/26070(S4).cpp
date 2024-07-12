using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

#include <cstdio>
#define min(a, b) (a<b?a:b)
#define ticket 1
#define human 0
int main() {
    int arr[3][2];
    FOR(i, 0, 3) scanf(" %d", &arr[i][human]);
    FOR(i, 0, 3) scanf(" %d", &arr[i][ticket]);
    long sum = 0;
    FOR(q, 0, 3)
    FOR(i, 0, 3) {
        int tmp = min(arr[i][ticket], arr[i][human]);
        sum += tmp;
        arr[i][ticket] -= tmp;
        arr[i][human] -= tmp;

        if(arr[i][ticket] < 3) continue;
        arr[(i+1)%3][ticket] += arr[i][ticket]/3;
        arr[i][ticket] %= 3;
    }
    printf("%ld\n", sum);
    return 0;
}