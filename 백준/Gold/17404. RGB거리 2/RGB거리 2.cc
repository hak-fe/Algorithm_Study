#include<bits/stdc++.h>
using namespace std;

#define MAX 2100000000
#define DIV 1000000007
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL)
#define endl '\n'

typedef unsigned long long ull;
typedef long long ll;

vector<vector<int>>cost;
vector<vector<int>>dp;
vector<vector<int>>beginnigPoint;

int main() {
	FASTIO;
	int n, minVal = MAX;
	cin >> n;
	cost.assign(n, vector<int>(3));
	dp.assign(n, vector<int>(3, MAX));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> cost[i][j];
		}
	}
	for (int start = 0; start < 3; start++)
	{

		dp[0][0] = (start == 0) ? cost[0][0] : MAX;
		dp[0][1] = (start == 1) ? cost[0][1] : MAX;
		dp[0][2] = (start == 2) ? cost[0][2] : MAX;

		for (int i = 1; i < n; i++)
		{
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
		}
		for (int c = 0; c < 3; c++) {
			if (c != start) minVal = min(minVal, dp[n - 1][c]);
		}
	}

	cout << minVal << ' ';

	return 0;
}