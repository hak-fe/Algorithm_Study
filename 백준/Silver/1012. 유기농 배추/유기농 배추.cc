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

int graph[51][51] = {0, };
bool visited[51][51] = {false, };
int dx[4] = { 0, 1, 0, -1 }; //우, 하, 좌, 상 방향
int dy[4] = { 1, 0, -1, 0 };

void bfs(int row, int col);
void aryIni(int row, int col);
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++)
	{
		int row, col, k;
		cin >> col >> row >> k;
		for (int j = 0; j < k; j++)
		{
			int x, y;
			cin >> x >> y;
			graph[x][y] = 1;
		}
		bfs(col, row);
		aryIni(col, row); // 배열 초기화
	}
}
void bfs(int row, int col) {

	queue<int>qx;
	queue<int>qy;
	int cnt = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (visited[i][j] || graph[i][j] == 0)
				continue;
			else {
				cnt++;
				visited[i][j] = true;
				qx.push(i);
				qy.push(j);
				while (!qx.empty() && !qy.empty())
				{
					int x = qx.front();
					int y = qy.front();
					qx.pop();
					qy.pop();
					for (int k = 0; k < 4; k++)
					{
						if (x + dx[k] < row && y + dy[k] < col &&
							!visited[x + dx[k]][y + dy[k]] && graph[x + dx[k]][y + dy[k]] == 1) {
							qx.push(x + dx[k]);
							qy.push(y + dy[k]);
							visited[x + dx[k]][y + dy[k]] = true;
						}
					}
				}
			}
		}
	}
	cout << cnt << '\n';
}

void aryIni(int row, int col) {
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			graph[i][j] = 0;
			visited[i][j] = false;
		}
	}
}