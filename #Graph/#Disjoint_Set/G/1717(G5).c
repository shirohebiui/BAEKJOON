#include <stdio.h>

void input_data();

void init(int n);
int parent[1000001];
int find(int x);
void _union(int a, int b);


int main() {
    int n, m; scanf("%d %d", &n, &m);
    init(n);
    for(int i=0; i<m; i++) {
        // 0 a b -> a, b집합 합치기
        // 1 a b -> a, b같은 집합인지 확인하고 **같은 집합이면 YES, 아니면 NO 출력**
        int mod, A, B; scanf(" %d %d %d", &mod, &A, &B);
        if(mod == 1) {
            if(find(A) == find(B)) printf("YES\n");
            else                   printf("NO\n");
        } else {
            _union(A, B);
        }
    }
    return 0;
}

void init(int n) {
    for(int i=1; i<=n; i++) {
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
    if(a < b) parent[a] = b;
    else parent[b] = a;
}