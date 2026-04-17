#include <iostream>
using namespace std;

int parent[100001];
int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int G, P; cin >> G >> P;
    for(int i=0; i<=G; i++) parent[i] = i;
    
    int ans = 0;
    for(int i=0; i<P; i++) {
        int g; cin >> g;
        int emptyGate = find(g);
        if(emptyGate == 0) break;
        parent[emptyGate] = emptyGate - 1;
        ans++;
    }
    cout << ans;
}