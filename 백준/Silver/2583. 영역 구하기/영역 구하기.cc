#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>
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

void bfs(int n, int m);

vector<vector<int>>grid;
vector<int> results;
int main() {
	FASTIO;
	int n, m, k, x1, y1, x2, y2;
	cin >> n >> m >> k;
	grid.assign(n, vector<int>(m));
	for (int i = 0; i < k; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		for (int c = y1; c < y2; c++)
		{
			for (int r = x1; r < x2; r++)
			{
				grid[c][r] = 1;
			}
		}
	}
	bfs(n, m);
	sort(results.begin(), results.end());
	cout << results.size() << endl;
	for (int i = 0; i < results.size(); i++)
	{
		cout << results[i] << ' ';
	}
	return 0;
}
void bfs(int n, int m) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int cnt;
			queue<pair<int, int>>q;
			q.push({ i,j });
			if (!grid[i][j]) {
				grid[i][j] = 1;
				cnt = 1;
			}
			else
				continue;
			while (!q.empty()) {
				int x = q.front().first, y = q.front().second;
				q.pop();
				for (int k = 0; k < 4; k++)
				{
					int nx = x + dx[k], ny = y + dy[k];
					if (nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1)
						continue;
					if (!grid[nx][ny]) {
						cnt++;
						grid[nx][ny] = 1;
						q.push({ nx, ny });
					}
				}
			}
			results.push_back(cnt);
		}
	}
	return;
}