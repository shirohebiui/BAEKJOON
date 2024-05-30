#include <iostream>
using namespace std;

#include <algorithm>
int cmp(const void *a, const void *b) {
    return *(int *)a > *(int *)b;
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    int cnt = n;
    int arr[1000] = {0, };
    while(cnt--) {
        cin >> arr[cnt];
    }
    qsort(arr, n, sizeof(int), cmp);
    long long sum = arr[0];
    long long res = arr[0];
    for(int i=1; i<n; i++) {
        sum += arr[i];
        res += sum;
        // cout << arr[i] << " ";
    }
    cout << res << "\n";
    return 0;
}