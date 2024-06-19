#include <iostream>
#include <queue>
#include <vector>
#define MaxNode 20000
#define INF 1e9
using namespace std;

struct edge{
    int vertex, weight;
    // edge(int v, int w) : vertex(v), weight(w) {}

    bool operator<(const edge& other) const {
        return weight > other.weight;
    }
};

vector<edge> graph[MaxNode];
int dist[MaxNode];
int vsize, esize, start;

void dijkstra(int start) {
    priority_queue<edge> pq;

    pq.push({start, 0});
    dist[start] = 0;
    while(!pq.empty()) {
        int min_dist = pq.top().weight;
        int now = pq.top().vertex;
        pq.pop();
        if(dist[now] < min_dist) continue;
        for(auto& edge : graph[now]) {
            int cost = min_dist + edge.weight;
            if(cost < dist[edge.vertex]) {
                dist[edge.vertex] = cost;
                pq.push({edge.vertex, cost}); 
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> vsize >> esize >> start; start--;
    while(esize--) {
        int v, u, weight;
        cin >> v >> u >> weight;
        graph[v-1].push_back({u-1, weight});
    }

    fill(dist, dist+vsize, INF);
    dijkstra(start);
    for(int i=0; i<vsize; i++) {
        if(dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
    return 0;
}