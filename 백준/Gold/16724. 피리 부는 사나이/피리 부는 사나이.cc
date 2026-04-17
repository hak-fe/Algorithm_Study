#include <iostream>
#include <vector>
using namespace std;

int parent[1000000];
int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}
void merge(int u, int v) {
    u = find(u); v = find(v);
    if(u != v) parent[u] = v;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N, M; cin >> N >> M;
    for(int i=0; i<N*M; i++) parent[i] = i;
    
    int ans = N * M;
    for(int i=0; i<N; i++) {
        string s; cin >> s;
        for(int j=0; j<M; j++) {
            int u = i * M + j, v = u;
            if(s[j] == 'U') v = (i-1)*M + j;
            else if(s[j] == 'D') v = (i+1)*M + j;
            else if(s[j] == 'L') v = i*M + j - 1;
            else if(s[j] == 'R') v = i*M + j + 1;
            
            if(find(u) != find(v)) {
                merge(u, v);
                ans--;
            }
        }
    }
    cout << ans;
}