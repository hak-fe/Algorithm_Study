#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <deque>
using namespace std;

int dp[31][31] = {};

int DP(int n, int m) {
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dp[i][j] = 0;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		dp[1][i] = i;
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = 2; j <= m; j++)
		{
			dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
		}
	}
	return dp[n][m];
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++)
	{
		int west, east;
		cin >> west >> east;
		cout << DP(west, east) << '\n';
	}
}