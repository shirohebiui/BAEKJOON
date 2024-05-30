#include <iostream>
#include <algorithm>
#include <vector>
#define MaxNode 1001

int vsize, esize;
typedef struct node {
    int s, e, weight;
}node;
std::vector<node> v;

bool cmp(node &s1, node &s2) {
    return s1.weight < s2.weight;
}

int parent[MaxNode];
void init_parent() {
    int x = vsize;
    while(x--) parent[x] = x;
}
int find(int x) {
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}
void _union(int a, int b) {
    a = find(a);
    b = find(b);
    a<b ? parent[a] = b : parent[b] = a;
}

int mst_weight;
void kruskal() {
    for(int i=0; i<v.size(); i++) {
        if(find(v[i].s) != find(v[i].e)) {
            _union(v[i].s, v[i].e);
            mst_weight += v[i].weight;
        }
    }
}
int main() {
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
    std::cin >> vsize >> esize;

    int start, end, weight;
    node i;
    while(esize--) {
        std::cin >> i.s >> i.e >> i.weight;
        v.push_back(i);
    }
    sort(v.begin(), v.end(), cmp); //오름차순
    init_parent();
    kruskal();
    std::cout << mst_weight << "\n";
    return 0;
}