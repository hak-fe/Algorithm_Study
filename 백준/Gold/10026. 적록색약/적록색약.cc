#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>

#define DEBUG 1
#define endl '\n'
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)
#define DIV 10007
#define MAX 2001

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int dz[2] = { 1, -1 };

vector<vector<char>>v;
vector<vector<int>>visited;
int bfs1(int size);
int bfs2(int size);
int main() {
	FASTIO;
	int n;
	cin >> n;

	v.assign(n, vector<char>(n, ' '));
	visited.assign(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> v[i][j];

	int a = bfs1(n);
	visited.assign(n, vector<int>(n, 0));
	int b = bfs2(n);

	cout << a << ' ' << b;

	return 0;
}
int bfs1(int size) {
	int area = 0;
	queue<pair<int, int>>q;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (visited[i][j] == 1)
				continue;
			else
				q.push(make_pair(i, j));

			while (!q.empty()) {
				int x = q.front().first, y = q.front().second;
				char color = v[x][y];
				q.pop();
				for (int k = 0; k < 4; k++)
				{
					int nx = x + dx[k], ny = y + dy[k];
					if (nx <0 || nx > size - 1 || ny < 0 || ny > size - 1) continue;
					if (v[nx][ny] == color && !visited[nx][ny]) {
						visited[nx][ny] = 1;
						q.push(make_pair(nx, ny));
					}
				}
			}
			area++;
		}
	}
	return area;
}
int bfs2(int size) {
	int area = 0;
	queue<pair<int, int>>q;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (visited[i][j] == 1)
				continue;
			else
				q.push(make_pair(i, j));

			while (!q.empty()) {
				int x = q.front().first, y = q.front().second;
				char color = v[x][y];
				q.pop();
				for (int k = 0; k < 4; k++)
				{
					int nx = x + dx[k], ny = y + dy[k];
					if (nx <0 || nx > size - 1 || ny < 0 || ny > size - 1) continue;
					if (!visited[nx][ny]) {
						if (color == 'R' && v[nx][ny] == 'R' ||
							color == 'R' && v[nx][ny] == 'G' ||
							color == 'G' && v[nx][ny] == 'G' ||
							color == 'G' && v[nx][ny] == 'R' ||
							color == 'B' && v[nx][ny] == 'B') {
							visited[nx][ny] = 1;
							q.push(make_pair(nx, ny));
						}
					}
				}
			}
			area++;
		}
	}
	return area;
}