#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<long long> A(n), B(n), C(n), D(n);
    for(int i=0; i<n; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];
    
    vector<long long> AB, CD;
    AB.reserve(n*n); CD.reserve(n*n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            AB.push_back(A[i] + B[j]);
            CD.push_back(C[i] + D[j]);
        }
    }
    
    sort(CD.begin(), CD.end());
    long long ans = 0;
    for(long long ab : AB) {
        long long target = -ab;
        ans += upper_bound(CD.begin(), CD.end(), target) - lower_bound(CD.begin(), CD.end(), target);
    }
    cout << ans;
}