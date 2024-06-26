#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

void swap(char *a, char *b) {
    char tmp = *a; *a = *b; *b = tmp;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int n, m; cin >> n >> m;
    char arr[101];
    FOR(i, 1, n+1) arr[i] = i;
    while(m-->0) {
        short a, b; cin >> a >> b;
        swap(&arr[a], &arr[b]);
    }
    FOR(i, 1, n+1) cout << (short)arr[i] << " ";

    return 0;
}