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
vector<pair<int, int>>coord; // 빙산의 좌표와 녹은 여부를 순서대로 저장하는 벡터 
// ㄴ (ex. 1,1,0 : 빙산의 좌표는 1, 1이고 아직 녹지 않음. / 2, 1, 1 : 빙산의 좌표는 2, 1이고 녹음)

int meltingIce(int n, int m);
int getAreaCnt(int x, int y, int n, int m);
void printArea(int n, int m) {
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) {
			cout << grid[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	return;
}
int main() {
	FASTIO;
	int n, m;
	cin >> n >> m;
	grid.assign(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) {
			cin >> grid[i][j];
			if (grid[i][j])
				coord.push_back(make_pair(i, j));
		}
	}
	if(DEBUG) printArea(n, m);
	cout << meltingIce(n, m);
	return 0;
}

int meltingIce(int n, int m) {
	if (coord.empty()) return 0;

	int year = 0;
	for (;; year++)
	{
		visited.assign(n + 1, vector<int>(m + 1, 0));
		int area = 0;
		// 1. 분리 확인하기
		for (int i = 0; i < coord.size(); i++)
		{
			int x = coord[i].first, y = coord[i].second;
			if (!grid[x][y]) continue;
			if (!visited[x][y])
				area += getAreaCnt(x, y, n, m);
		}
		if (area >= 2)
			return year;
		if (!area)
			return 0;
		// 2. 빙하 녹이기
		vector<tuple<int, int, int>>meltingInfo; //녹이는 빙산의 좌표와 빼야 하는 값을 순서대로 저장
		for (int i = 0; i < coord.size(); i++)
		{
			int x = coord[i].first, y = coord[i].second;
			if (!grid[x][y]) continue;
			int difCnt = 0; // 주변에 0이 몇 개 있는가?
			for (int j = 0; j < 4; j++)
			{
				int nx = x + dx[j], ny = y + dy[j];
				if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
				if (!grid[nx][ny])
					difCnt++;
			}
			if (difCnt)
				meltingInfo.push_back(make_tuple(x, y, difCnt));
		}
		for (int i = 0; i < meltingInfo.size(); i++)
		{
			int x = get<0>(meltingInfo[i]), y = get<1>(meltingInfo[i]);
			int temp = grid[x][y] - get<2>(meltingInfo[i]);
			if (temp <= 0) {
				grid[x][y] = 0;
			}
			else
				grid[x][y] = temp;
		}
		if (DEBUG) printArea(n, m);
		// 3. year 1 증가시키기

		// 4. 재사용 변수들 초기화
	}
	return year;
}
int getAreaCnt(int x, int y, int n, int m) {
	queue<pair<int, int>>q;
	q.push(make_pair(x, y));
	visited[x][y] = 1;
	while (!q.empty()) {
		pair<int, int>p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = p.first + dx[i], ny = p.second + dy[i];
			if (nx < 1 || nx > n || ny < 1 || ny > m || !grid[nx][ny]) continue;
			if (!visited[nx][ny]) {
				visited[nx][ny] = 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
	return 1;
}