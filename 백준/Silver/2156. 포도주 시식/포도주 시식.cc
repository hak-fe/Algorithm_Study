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
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)

using namespace std;
typedef long long int ll;
ll max(ll a, ll b) {
	return a > b ? a : b;
}
ll dp[10000];
ll juice[10000];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> juice[i];
	}

	dp[0] = juice[0];
	dp[1] = dp[0] + juice[1];
	dp[2] = max(dp[1], max(juice[0] + juice[2], juice[1] + juice[2]));

	for (int i = 3; i < n; i++)
	{
		dp[i] = max(
			dp[i - 1],
			max(juice[i] + juice[i - 1] + dp[i - 3],
			juice[i] + dp[i - 2]));
	}
	cout << max(dp[n - 1], dp[n - 2]);
	return 0;
}