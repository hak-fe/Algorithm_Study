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
#include <cstring>

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
/*
	맵을 전부 확인하며 국경선 열 수 있는 곳 있는지 확인
		- 못 열면 끝
		- 열 수 있는 경우
			n*n 국가들에게 고유 번호를 부여함.
			국경을 열 수 있는 두 국가의 국경이 열렸다는 걸 표시.
			인접한 또 다른 국가가 열릴 수 있는지 확인함.
			.... 전부 순회하며 확인하기
			열린 국가들의 인구의 평균값 계산하여 분배
			국경 전부 닫기
				-끝- : 다시 위의 과정 반복
*/
vector<vector<int>>grid; // 각 국가의 인구수 저장
vector<vector<int>>visited; // 국경 열림 판단용 배열
int bfs(int n, int l, int r);
int main() {
	FASTIO;
	int n, l, r;
	cin >> n >> l >> r;

	grid.assign(n + 1, vector<int>(n + 1));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) {
			cin >> grid[i][j];
		}
	}
	cout << bfs(n, l, r);
	return 0;
}

int bfs(int n, int l, int r) {
	for (int day = 0;; day++)
	{
		int moved = 0;
		visited.assign(n + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++) {
				if (visited[i][j])
					continue;
				visited[i][j] = 1;
				int sum = grid[i][j];
				queue < pair<int, int>>q;
				vector<pair<int, int>>numberOfOpenedBoarder; // 국경이 열린 국가의 수(중복X)
				numberOfOpenedBoarder.push_back({ i, j });
				q.push({ i, j });
				while (!q.empty()) {
					int x = q.front().first, y = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++)
					{
						int nx = x + dx[k], ny = y + dy[k];
						if (nx < 1 || nx > n || ny < 1 || ny > n)
							continue;
						if (visited[nx][ny]) 
							continue;
						int dif = abs(grid[x][y] - grid[nx][ny]);
						if (dif >= l && dif <= r) {
							numberOfOpenedBoarder.push_back({ nx, ny });
							moved = 1;
							visited[nx][ny] = 1;
							q.push({ nx, ny });
							sum += grid[nx][ny];
						}
					}
				}
				if (numberOfOpenedBoarder.size() > 1) {
					sum /= numberOfOpenedBoarder.size();
					for (auto k : numberOfOpenedBoarder) {
						grid[k.first][k.second] = sum;
					}
				}
			}
		}
		if (!moved)
			return day;
	}
}