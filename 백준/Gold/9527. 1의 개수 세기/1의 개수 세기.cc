#include <iostream>
using namespace std;
typedef long long ll;

ll countOnes(ll x) {
    if (x <= 0) return 0;
    ll cnt = 0;
    for(ll i=0; (1LL << i) <= x; i++) {
        ll period = 1LL << (i + 1);
        cnt += (x + 1) / period * (1LL << i);
        ll rem = (x + 1) % period;
        cnt += max(0LL, rem - (1LL << i));
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll A, B; cin >> A >> B;
    cout << countOnes(B) - countOnes(A - 1);
}