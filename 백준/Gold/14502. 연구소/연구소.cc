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

vector<vector<int>>lab;
vector<vector<int>>labTemp;
queue<pair<int, int>> virusCoord;
vector<pair<int, int>> zeroCoord;
vector<pair<int, int>>wallsCoord;
vector<int> zeroVisited;
int maxArea = 0;

void initLab(int n, int m);
void installWalls(int n, int m, int depth);
void spreadingVirus(int n, int m);
int countSafetyArea(int n, int m);

int main() {
	FASTIO;
	int n, m;
	cin >> n >> m;
	lab.assign(n + 1, vector<int>(m + 1));
	labTemp.assign(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) {
			cin >> lab[i][j];
			if (lab[i][j] == 2)
				virusCoord.push({ i, j });
			else if (lab[i][j] == 0)
				zeroCoord.push_back({ i, j });
		}
	}
	zeroVisited.assign(zeroCoord.size(), 0);
	initLab(n, m);
	installWalls(n, m, 0);
	cout << maxArea;
}

void initLab(int n, int m) {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			labTemp[i][j] = lab[i][j];
}
void installWalls(int n, int m, int depth) {
	if (depth == 3) {
		spreadingVirus(n, m);
		maxArea = max(maxArea, countSafetyArea(n, m));
		initLab(n, m);
		for (int i = 0; i < 3; i++)
			labTemp[wallsCoord[i].first][wallsCoord[i].second] = 1;
		return;
	}

	int size = zeroVisited.size();
	for (int i = 0; i < size; i++)
	{
		if (!zeroVisited[i]) {
			int x = zeroCoord[i].first;
			int y = zeroCoord[i].second;
			labTemp[x][y] = 1;
			wallsCoord.push_back({ x, y });
			zeroVisited[i] = 1;
			installWalls(n, m, depth + 1);
			labTemp[x][y] = 0;
			wallsCoord.pop_back();
			zeroVisited[i] = 0;
		}
	}
}
void spreadingVirus(int n, int m) {
	//0은 빈 칸, 1은 벽, 2는 바이러스
	queue<pair<int, int>>coord = virusCoord;
	while (!coord.empty()) {
		int x = coord.front().first;
		int y = coord.front().second;
		coord.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
				if (labTemp[nx][ny] == 0) {
					labTemp[nx][ny] = 2;
					coord.push({ nx, ny });
				}
			}
		}
	}
}
int countSafetyArea(int n, int m) {
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (!labTemp[i][j])
				cnt++;
	return cnt;
}