#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<=(end); ++val)

int node[50], parent[50], leaf[50], del_node;

int find(int x) {
    if(node[x] != 0) {
        return node[x];
    } else if(parent[x] == del_node) {
        return node[x] = -1; //삭제된 노드(트리)
    } else if(parent[x] == -1) {
        return node[x] = 1; //유효한 노드(트리)
    } else {
        return node[x] = find(parent[x]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // node[x] != 0 --> is Not LeafNode

    int vsize; cin >> vsize;
    FOR(i, 0, vsize-1) {
        cin >> parent[i];
    }
    cin >> del_node;
    node[del_node] = -1;
    FOR(i, 0, vsize-1) {
        find(i);
    }
    
    //func
    int leaf_node = 0;
    FOR(i, 0, vsize-1) {
        if(node[i] == 1) {
            if(parent[i] >= 0) ++leaf[parent[i]];
        }
    }

    FOR(i, 0, vsize-1) {
        if(node[i] == 1 && leaf[i] == 0) {
            ++leaf_node;
        }
    }
    cout << leaf_node << "\n";
    return 0;
}