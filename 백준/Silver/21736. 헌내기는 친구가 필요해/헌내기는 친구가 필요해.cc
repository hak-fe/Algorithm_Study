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

vector<vector<char>>space;
vector<vector<int>>visited;

int bfs(int r, int c, int sr, int sc);

int main() {
	FASTIO;
	int n, m, sr, sc, res;
	cin >> n >> m;
	space.assign(n, vector<char>(m, 'O'));
	visited.assign(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> space[i][j];
			if (space[i][j] == 'I') {
				visited[i][j] = 1;
				sr = i;
				sc = j;
			}
		}
	}
	res = bfs(n, m, sr, sc);
	if (res == 0)
		cout << "TT";
	else
		cout << res;
	return 0;
}

int bfs(int r, int c, int sr, int sc){
	int cnt = 0;
	queue<pair<int, int>>q;
	q.push(make_pair(sr, sc));
	
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx > r - 1 || ny < 0 || ny > c - 1) continue;
			if (space[nx][ny] != 'X' && !visited[nx][ny]) {
				if (space[nx][ny] == 'P')
					cnt++;
				q.push(make_pair(nx, ny));
				visited[nx][ny] = 1;
			}
		}
	}
	return cnt;
}