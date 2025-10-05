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

vector<vector<int>>grid;
vector<vector<vector<int>>>visited;

int bfs(int n, int m);

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
			grid[i][j] = ch - '0';
		}
	}
	visited.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		visited[i].resize(m + 1);
		for (int j = 1; j <= m; j++)
		{
			visited[i][j].assign(2, INF);
		}
	}
	visited[1][1][0] = 1;
	int res = bfs(n, m);
	cout << ((res == INF) ? -1 : res);
	return 0;
}
int bfs(int n, int m) {
	queue<tuple<int, int, int>>q;
	q.push({ 1,1,0 });
	while (!q.empty()) {
		int x = get<0>(q.front()), y = get<1>(q.front()), brokenCount = get<2>(q.front());
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
				if (!grid[nx][ny]) {
					// 벽이 아닌 경우, grid[nx][ny] == 0
					if (visited[nx][ny][brokenCount] == INF) {
						visited[nx][ny][brokenCount] = visited[x][y][brokenCount] + 1;
						q.push({ nx, ny, brokenCount });
					}
				}
				else {
					//벽인 경우 grid[nx][ny] == 1
					if (!brokenCount) {
						//brokenCount가 0인 경우, 아직 벽을 부수지 않았으므로 brokenCount 1 증가시키고 거리 값 경신
						if (visited[nx][ny][1] == INF) {
							// 첫 번째로 도달한 경우만 계산하도록 하기
							visited[nx][ny][brokenCount + 1] = visited[x][y][brokenCount] + 1;
							q.push({ nx, ny, brokenCount + 1 });
						}
					}
					//brokenCount가 이미 1인경우는 벽을 부술 수 없으므로 더 이상 나아갈 수 없음. => 큐에 넣지 않기
				}
			}
		}
	}
	return min(visited[n][m][0], visited[n][m][1]);
}