#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long T; int n, m;
    cin >> T >> n;
    vector<long long> A(n); for(int i=0; i<n; i++) cin >> A[i];
    cin >> m;
    vector<long long> B(m); for(int i=0; i<m; i++) cin >> B[i];

    vector<long long> sumA, sumB;
    for(int i=0; i<n; i++) {
        long long sum = 0;
        for(int j=i; j<n; j++) { sum += A[j]; sumA.push_back(sum); }
    }
    for(int i=0; i<m; i++) {
        long long sum = 0;
        for(int j=i; j<m; j++) { sum += B[j]; sumB.push_back(sum); }
    }
    
    sort(sumB.begin(), sumB.end());
    long long ans = 0;
    for(auto a : sumA) {
        long long target = T - a;
        ans += upper_bound(sumB.begin(), sumB.end(), target) - lower_bound(sumB.begin(), sumB.end(), target);
    }
    cout << ans;
}