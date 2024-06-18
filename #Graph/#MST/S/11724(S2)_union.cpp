#include <iostream>
using namespace std;

int parent[1001];
int vsize, esize;
void init(int vsize) {
    for(int i=1; i<=vsize; i++) {
        parent[i] = i;
    }
}

int find(int x) {
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void _union(int a, int b) {
    a = find(a);
    b = find(b);
    a < b ? parent[a] = b : parent[b] = a;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> vsize >> esize;
    init(vsize);
    int start, end;
    while(esize--) {
        cin >> start >> end;
        _union(start, end);
    }
    int connected_componenet = 0;
    for(int x=1; x<=vsize; x++) {
        if(parent[x] == x)
            connected_componenet++;
    }
    cout << connected_componenet << "\n";
    return 0;
}