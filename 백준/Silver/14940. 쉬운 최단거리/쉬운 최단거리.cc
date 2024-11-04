#define INF 1000000000
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int map[1000][1000];
int res[1000][1000] = { 0 };
int visited[1000][1000] = { 0 };
void bfs(int goalX, int goalY, int sizeX, int sizeY);

int main() {
	int n, m, goalX = 0, goalY = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				goalX = i;
				goalY = j;
			}
		}
	}
	
	bfs(goalX, goalY, n, m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] != 0 && visited[i][j] == 0)
				res[i][j] = -1;
			cout << res[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
void bfs(int goalX, int goalY, int sizeX, int sizeY) {
	int x, y;
	queue<int>qx;
	queue<int>qy;
	qx.push(goalX);
	qy.push(goalY);
	visited[goalX][goalY] = 1;
	while (!qx.empty() && !qy.empty()) {
		x = qx.front();
		y = qy.front();
		qx.pop();
		qy.pop();
		if (y + 1 <= sizeY - 1 && visited[x][y + 1] == 0 && map[x][y + 1] != 0)
		{
			qx.push(x);
			qy.push(y + 1);
			visited[x][y + 1] = 1;
			res[x][y + 1] = res[x][y] + 1;
		}
		if (x + 1 <= sizeX - 1 && visited[x + 1][y] == 0 && map[x + 1][y] != 0)
		{
			qx.push(x + 1);
			qy.push(y);
			visited[x + 1][y] = 1;
			res[x + 1][y] = res[x][y] + 1;
		}
		if (y - 1 >= 0 && visited[x][y - 1] == 0 && map[x][y - 1] != 0)
		{
			qx.push(x);
			qy.push(y - 1);
			visited[x][y - 1] = 1;
			res[x][y - 1] = res[x][y] + 1;
		}
		if (x - 1 >= 0 && visited[x - 1][y] == 0 && map[x - 1][y] != 0)
		{
			qx.push(x - 1);
			qy.push(y);
			visited[x - 1][y] = 1;
			res[x - 1][y] = res[x][y] + 1;
		}
	}
}