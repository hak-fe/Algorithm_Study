#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>

#define DEBUG 0
#define endl '\n'
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)
#define DIV 10007
#define INF 2100000000
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int dz[2] = { 1, -1 };

vector<vector<int>>grid;
vector<vector<int>>dp;
int res = 0;
int dfs(int x, int y, int n, int m);
int main() {
	int n, m;
	cin >> n >> m;
	grid.assign(n, vector<int>(m));
	dp.assign(n, vector<int>(m, -1));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {

			cin >> grid[i][j];
		}
	}
	dp[n - 1][m - 1] = 1;
	dfs(0, 0, n - 1, m - 1);
	cout << dp[0][0];
	return 0;
}
int dfs(int x, int y, int n, int m) {
	if (dp[x][y] != -1)
		return dp[x][y];
	dp[x][y] = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || nx > n || ny < 0 || ny > m || grid[nx][ny] >= grid[x][y])
			continue;
		dp[x][y] += dfs(nx, ny, n, m);
	}
	return dp[x][y];
}
