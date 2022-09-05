#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <deque>
#include <utility>

#define MIN 0
#define MAX 10000000

using namespace std;
typedef unsigned long long int ll;

int graph[101][101];
bool visited[101][101] = { false, };
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int cnt[101][101] = { 0 , };
int ans = MAX;

void bfs(int x);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//bfs 사용
	int n, m;
	string str;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		for (int j = 0; j < m; j++)
		{
			graph[i + 1][j + 1] = str[j] - '0';
		}
	}
	cnt[n][m] = MAX;
	bfs(1);
	cout << cnt[n][m] << '\n';
}
void bfs(int start) {
	queue<int> qx;
	queue<int> qy;
	qx.push(start);
	qy.push(start);
	visited[start][start] = true;
	cnt[start][start] = 1;
	while (!qx.empty() && !qy.empty()) {
		int x = qx.front();
		int y = qy.front();
		qx.pop();
		qy.pop();

		for (int i = 0; i < 4; i++)
		{
			if (!visited[x + dx[i]][y + dy[i]] && graph[x + dx[i]][y + dy[i]] == 1)
			{
				//방문하지 않았고, 움직일 수 있는 칸을 나타내는 1인가?
				qx.push(x + dx[i]);
				qy.push(y + dy[i]);
				cnt[x + dx[i]][y + dy[i]] = cnt[x][y] + 1;
				//cout << x + dx[i] << "탐색, " << y + dy[i] << "탐색, 카운트 값 : "
					//<< cnt[x + dx[i]][y + dy[i]] << '\n';;
				visited[x + dx[i]][y + dy[i]] = true;
			}
		}
	}
}