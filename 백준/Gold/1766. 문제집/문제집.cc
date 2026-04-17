#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N, M; cin >> N >> M;
    vector<vector<int>> adj(N+1);
    vector<int> ind(N+1, 0);
    
    for(int i=0; i<M; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        ind[b]++;
    }
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=1; i<=N; i++) if(ind[i] == 0) pq.push(i);
    
    while(!pq.empty()) {
        int curr = pq.top(); pq.pop();
        cout << curr << " ";
        for(int next : adj[curr]) {
            if(--ind[next] == 0) pq.push(next);
        }
    }
}