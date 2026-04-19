#include <bits/stdc++.h>
using namespace std;

int parent[51];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) parent[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) parent[i] = i;

    int t;
    cin >> t;

    vector<int> truth(t);
    for (int i = 0; i < t; i++) cin >> truth[i];

    vector<vector<int>> party(M);

    for (int i = 0; i < M; i++) {
        int cnt;
        cin >> cnt;
        party[i].resize(cnt);
        for (int j = 0; j < cnt; j++) {
            cin >> party[i][j];
            if (j > 0) unite(party[i][0], party[i][j]);
        }
    }

    for (int i = 1; i < truth.size(); i++) {
        unite(truth[0], truth[i]);
    }

    int ans = 0;

    for (int i = 0; i < M; i++) {
        bool lie = true;
        for (int x : party[i]) {
            if (t > 0 && find(x) == find(truth[0])) {
                lie = false;
                break;
            }
        }
        if (lie) ans++;
    }

    cout << ans;
}