#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>

#define DEBUG 1
#define endl '\n'
#define DIV 10007
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

ll max(ll a, ll b) {
	return a > b ? a : b;
}

ll power(ll a, ll b) {

	ll res = 1;
	for (int i = 0; i < b - 2; i++)
	{
		res *= a;
		res %= DIV;
	}
	return res;
}


ull dp[1001];

int main() {
	int n;
	cin >> n;

	dp[1] = 10;
	for (int i = 2; i <= n; i++)
	{
		ll temp = power(i, DIV);
		dp[i] = (dp[i - 1] * (9 + i) * temp) % DIV;
	}
	cout << dp[n];
}