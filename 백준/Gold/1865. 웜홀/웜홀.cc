#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int s, e, t;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int TC; cin >> TC;
    while (TC--) {
        int N, M, W;
        cin >> N >> M >> W;

        vector<Edge> edges;

        // 도로 (양방향)
        for (int i = 0; i < M; i++) {
            int s, e, t;
            cin >> s >> e >> t;
            edges.push_back({s, e, t});
            edges.push_back({e, s, t});
        }

        // 웜홀 (단방향, 음수)
        for (int i = 0; i < W; i++) {
            int s, e, t;
            cin >> s >> e >> t;
            edges.push_back({s, e, -t});
        }

        vector<int> dist(N+1, 0);

        bool cycle = false;

        // Bellman-Ford
        for (int i = 1; i <= N; i++) {
            for (auto &ed : edges) {
                if (dist[ed.e] > dist[ed.s] + ed.t) {
                    dist[ed.e] = dist[ed.s] + ed.t;
                    if (i == N) cycle = true;
                }
            }
        }

        cout << (cycle ? "YES\n" : "NO\n");
    }
}