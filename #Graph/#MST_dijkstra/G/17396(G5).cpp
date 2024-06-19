#include <iostream>
#include <queue>
#include <vector>
#define MaxNode 100001
#define INF 21474836470
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

struct edge{
    int vertex; long weight;
    
    bool operator<(const edge& other) const {
        return weight > other.weight;
    }
};

vector<edge> graph[MaxNode];
long dist[MaxNode];
int vsize, esize;

void dijkstra(int start) {
    priority_queue<edge> pq;

    pq.push({start, 0});
    dist[start] = 0;
    while(!pq.empty()) {
        long min_dist = pq.top().weight;
        int now = pq.top().vertex;
        pq.pop();
        if(dist[now] < min_dist) continue;
        FOR(i, 0, graph[now].size()) {
            long cost = min_dist + graph[now][i].weight;
            if(cost < dist[graph[now][i].vertex]) {
                dist[graph[now][i].vertex] = cost;
                pq.push({graph[now][i].vertex, cost});
            }
        }
    }
}

#include <bitset>
bitset<MaxNode> b;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> vsize >> esize;
    FOR(i, 0, vsize) {
        int valid; cin >> valid;
        if(valid) b[i] = 1;
    }
    b[vsize-1] = 0;
    while(esize--) {
        int v, u, weight;
        cin >> v >> u >> weight;
        if(b[v] == 0 && b[u] == 0) {
            graph[v].push_back({u, weight});
            graph[u].push_back({v, weight});
        }
    }
    fill(dist, dist+vsize, INF);
    dijkstra(0);
    if(dist[vsize-1] < INF) cout << dist[vsize-1] << "\n";
    else cout << "-1\n";
    return 0;
}