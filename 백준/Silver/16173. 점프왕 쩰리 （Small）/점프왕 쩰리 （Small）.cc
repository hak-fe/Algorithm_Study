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
vector<vector<int>>visited;
int isDone = 0;

void dfs(int x, int y, int n) {
	int stepX[2] = { 0,  grid[x][y] };
	int stepY[2] = { grid[x][y], 0 };
	for (int i = 0; i <= 1; i++)
	{
		if (isDone)
			return;
		int nx = x + stepX[i], ny = y + stepY[i];
		if (nx < 1 || nx > n || ny < 1 || ny > n)
			continue;
		if (nx == n && ny == n) {
			isDone = 1;
			return;
		}
		if (!visited[nx][ny]) {
			visited[nx][ny] = 1;
			dfs(nx, ny, n);
			visited[nx][ny] = 0;
		}
	}
	return;
}

int main() {
	FASTIO;
	int n;
	cin >> n;
	grid.assign(n + 1, vector<int>(n + 1));
	visited.assign(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) {
			cin >> grid[i][j];
		}
	}
	visited[1][1] = 1;
	dfs(1, 1, n);
	if (isDone)
		cout << "HaruHaru";
	else
		cout << "Hing";
}