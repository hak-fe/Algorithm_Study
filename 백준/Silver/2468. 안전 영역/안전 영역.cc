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

vector<vector<int>>ground;
vector<vector<int>>visited;

int getCurrntSafetyAreaNumber(int n, int waterLevel);

int main() {
	FASTIO;
	int n, maxWaterLevel = 0, minWaterLevel = 100, res = 1;
	cin >> n;
	ground.assign(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> ground[i][j];
			maxWaterLevel = max(ground[i][j], maxWaterLevel);
			minWaterLevel = min(ground[i][j], minWaterLevel);
		}
	}

	for (int i = minWaterLevel; i <= maxWaterLevel; i++)
		res = max(res, getCurrntSafetyAreaNumber(n, i));

	cout << res;
}

int getCurrntSafetyAreaNumber(int n, int waterLevel) {
	visited.assign(n, vector<int>(n, 0));
	int cnt = 0;
	queue<pair<int, int>>q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && ground[i][j] - waterLevel > 0) {
				visited[i][j] = 1;
				q.push({ i, j });
				while (!q.empty()) {
					int x = q.front().first, y = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++)
					{
						int nx = x + dx[k], ny = y + dy[k];
						if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
							if (!visited[nx][ny] && ground[nx][ny] - waterLevel > 0) {
								q.push({ nx, ny });
								visited[nx][ny] = 1;
							}
						}
					}
				}
				cnt++;
			}
		}
	}
	return cnt;
}