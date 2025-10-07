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
vector<vector<int>>grid;
vector<vector<int>>visited;
vector<pair<int, int>>coordOfOnes;

pair<int, int> bfs(int n, int m);

int main() {
	FASTIO;
	int n, m;
	cin >> n >> m;
	grid.assign(n + 1, vector<int>(m + 1));
	visited.assign(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) {
			cin >> grid[i][j];
			if (grid[i][j])
				coordOfOnes.push_back({ i, j });
		}
	}
	if (coordOfOnes.size() == 0)
		cout << 0 << endl << 0;
	else {
		pair<int, int>tp = bfs(n, m);
		cout << tp.first << endl << tp.second;
	}

	return 0;
}

pair<int,int> bfs(int n, int m) {
	pair<int, int>res;
	res.first = 0; // 그림의 개수
	res.second = 0; // 가장 넓은 그림의 넓이
	for (int i = 0; i < coordOfOnes.size(); i++)
	{
		int cnt = 1;
		queue<pair<int, int>>q;
		int x = coordOfOnes[i].first, y = coordOfOnes[i].second;
		if (!visited[x][y])
			res.first++;
		else 
			continue;
		q.push({ x,y });
		visited[x][y] = 1;
		while (!q.empty()) {
			x = q.front().first, y = q.front().second;
			q.pop();
			for (int j = 0; j < 4; j++)
			{
				int nx = x + dx[j], ny = y + dy[j];
				if (nx < 1 || nx > n || ny < 1 || ny > m) 
					continue;
				if (!visited[nx][ny] && grid[nx][ny]) {
					visited[nx][ny] = 1;
					cnt++;
					q.push({ nx, ny });
				}
			}
		}
		res.second = max(res.second, cnt);
	}
	return res;
}