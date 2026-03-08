#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 10000
#define DIV 1000000007
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL)
#define endl '\n'

typedef unsigned long long ull;
typedef long long ll;
vector<vector<int>>grid; // 입력값 저장
vector<vector<int>>dp; // 최댓값 계산 할 곳
void solve() {
	int n, m;
	cin >> n >> m;
	grid.assign(n + 1, vector<int>(m + 1));
	dp.assign(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) {
			cin >> grid[i][j];
		}
	}

	dp[1][1] = grid[1][1];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) {
			if (i + 1 <= n) {
				dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + grid[i + 1][j]);
			}
			if (j + 1 <= m) {
				dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + grid[i][j + 1]);
			}
			if (i + 1 <= n && j + 1 <= m) {
				dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + grid[i + 1][j + 1]);
			}
		}
	}
	cout << dp[n][m];
}

int main() {
	FASTIO;
	solve();
	return 0;
}