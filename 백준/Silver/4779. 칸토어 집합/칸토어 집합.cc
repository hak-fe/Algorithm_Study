#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long int ll;
ll power(ll n, ll x);
void recur(ll left, ll right);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, pow;
	while (cin >> n) {
		pow = power(3, n);
		recur(1, pow);
		cout << '\n';
	}
	return 0;
}
void recur(ll left, ll right) {
	if (left == right && left == 1){
		cout << '-';
		return;
	}
	recur(left, right / 3);
	for (ll i = 0; i < right/3; i++)
		cout << ' ';
	recur(left, right / 3);
}
ll power(ll n, ll x) {
	if (x == 0) return 1;
	for (int i = 1; i < x; i++)
	{
		n = n * 3;
	}
	return n;
}