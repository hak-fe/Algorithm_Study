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

pair<int, int> knightLocation[8] = { {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2} };
vector<vector<int>>visited;
int bfs(pair<int, int>start, pair<int, int>end, int maxLen);

int main() {
	
	int t, size;
	pair<int, int> start, end;
	cin >> t;
	while (t--) {
		cin >> size;
		cin >> start.first >> start.second;
		cin >> end.first >> end.second;
		cout << bfs(start, end, size) << endl;
	}
	return 0;

}

int bfs(pair<int, int>start, pair<int, int>end, int maxLen){
	if (start == end) 
		return 0;
	visited.assign(maxLen, vector<int>(maxLen, -1));
	queue<pair<int, int>>q;
	q.push({ start.first, start.second });
	visited[start.first][start.second] = 0;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int nx = x + knightLocation[i].first, ny = y + knightLocation[i].second;
			if (nx >= 0 && nx < maxLen && ny >= 0 && ny < maxLen) {
				if (visited[nx][ny] < 0) {
					if(end.first == nx && end.second == ny)
						return visited[x][y] + 1;
					q.push({ nx, ny });
					visited[nx][ny] = visited[x][y] + 1;
				}
			}
		}
	}
}