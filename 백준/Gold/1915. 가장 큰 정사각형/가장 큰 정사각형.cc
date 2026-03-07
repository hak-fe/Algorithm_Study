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
vector<vector<int>>grid;
int solve(int n, int m) {
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) {
			if (!grid[i][j]) continue;
			grid[i][j] = min(grid[i][j - 1], min(grid[i - 1][j], grid[i - 1][j - 1])) + 1;
			res = max(grid[i][j], res);
		}
	}
	return res * res;
}
int main() {
	FASTIO;
	char ch;
	int n, m;
	cin >> n >> m;

	grid.assign(n + 1, vector<int>(m + 1));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) {
			cin >> ch;
			grid[i][j] = ch -'0';
		}
	}

	cout << solve(n, m);
	return 0;
}