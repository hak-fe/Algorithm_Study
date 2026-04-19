#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int N, E;
vector<pair<int,int>> adj[801];
long long dist[801];

void dijkstra(int start) {
    fill(dist, dist + 801, INF);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [cost, now] = pq.top();
        pq.pop();

        if (dist[now] < cost) continue;

        for (auto [next, w] : adj[now]) {
            long long nextCost = cost + w;
            if (dist[next] > nextCost) {
                dist[next] = nextCost;
                pq.push({nextCost, next});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> E;

    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    int v1, v2;
    cin >> v1 >> v2;

    // 1 -> v1 -> v2 -> N
    dijkstra(1);
    long long d1 = dist[v1];
    long long d2 = dist[v2];

    dijkstra(v1);
    long long d3 = dist[v2];
    long long d4 = dist[N];

    dijkstra(v2);
    long long d5 = dist[v1];
    long long d6 = dist[N];

    long long path1 = d1 + d3 + d6;
    long long path2 = d2 + d5 + d4;

    long long ans = min(path1, path2);

    if (ans >= INF) cout << -1;
    else cout << ans;
}