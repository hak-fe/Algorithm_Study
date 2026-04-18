#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N+1);
    vector<int> indegree(N+1, 0);

    for (int i = 0; i < M; i++) {
        int k; cin >> k;
        vector<int> order(k);
        for (int j = 0; j < k; j++) cin >> order[j];
        for (int j = 0; j < k-1; j++) {
            adj[order[j]].push_back(order[j+1]);
            indegree[order[j+1]]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= N; i++)
        if (indegree[i] == 0) q.push(i);

    vector<int> result;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        result.push_back(cur);
        for (int next : adj[cur]) {
            if (--indegree[next] == 0)
                q.push(next);
        }
    }

    if ((int)result.size() != N) {
        cout << 0;
    } else {
        for (int i = 0; i < (int)result.size(); i++) {
            cout << result[i];
            if (i < (int)result.size()-1) cout << '\n';
        }
    }

    return 0;
}