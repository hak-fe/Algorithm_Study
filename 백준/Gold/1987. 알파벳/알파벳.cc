#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#include <stdlib.h>

#define DEBUG 0
#define endl '\n'
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)
#define DIV 10000
#define MAX 100001
#define INF 2100000000
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int dz[2] = { 1, -1 };

vector<vector<char>>grid;
int visited[26];
int maxLen = 1;

void dfs(int r, int c, int x, int y, int curLen);

int main() {
	FASTIO;
	int r, c;
	cin >> r >> c;

	grid.assign(r + 1, vector<char>(c + 1));
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++) {
			cin >> grid[i][j];
		}
	}
	visited[grid[1][1] - 'A'] = 1;
	dfs(r, c, 1, 1, 1);
	cout << maxLen;
	return 0;
}

void dfs(int r, int c, int x, int y, int curLen) {
	maxLen = max(curLen, maxLen);
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 1 || nx > r || ny < 1 || ny > c)
			continue;
		if (!visited[grid[nx][ny] - 'A']) {
			visited[grid[nx][ny] - 'A'] = 1;
			dfs(r, c, nx, ny, curLen + 1);
			visited[grid[nx][ny] - 'A'] = 0;
		}
	}
	return;
}