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
#define DIV 1000000000
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

ll max(ll a, ll b) {
	return a > b ? a : b;
}

ll dp[201][201];

int main() {
	int n, k;
	cin >> n >> k;


	for (int i = 0; i <= k; i++)
		dp[0][i] = 1;

	for (int i = 1; i <= n; i++)
	{
		dp[i][1] = 1;
		dp[i][2] = i + 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 3; j <= k; j++) {
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % DIV;
		}
	}
	cout << dp[n][k];
}