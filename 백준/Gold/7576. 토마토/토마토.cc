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

int graph[1001][1001] = { 0, };
bool visited[1001][1001] = { false, };
int dx[4] = { 0, 1, 0, -1 }; //우, 하, 좌, 상 방향
int dy[4] = { 1, 0, -1, 0 };
int day = 0;
int zeroCnt = 0;
queue<int>qx;
queue<int>qy;
void bfs(int n, int m);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i + 1][j + 1];
			if (graph[i + 1][j + 1] == 1) {
				qx.push(i + 1);
				qy.push(j + 1);
			}
			else if (graph[i + 1][j + 1] == 0)
				zeroCnt++;
		}
	}
	if (zeroCnt == 0) {
		cout << 0 << '\n';
		return 0;
	}
	bfs(n, m);
	if (zeroCnt > 0)
		cout << -1 << '\n';
	else
		cout << day << '\n';
}
void bfs(int n, int m) {
	int temp = 0;
	int x = 0;
	int y = 0;
	while (!qx.empty() && !qy.empty()) {
		int size = qx.size();
		for (int i = 0; i < size; i++)
		{
			x = qx.front();
			y = qy.front();
			qx.pop();
			qy.pop();
			for (int j = 0; j < 4; j++)
			{
				if (x + dx[j] > 0 && x + dx[j] < n + 1 &&
					y + dy[j] > 0 && y + dy[j] < m + 1) {
					if (!visited[x + dx[j]][y + dy[j]] && graph[x + dx[j]][y + dy[j]] == 0) {
						qx.push(x + dx[j]);
						qy.push(y + dy[j]);
						visited[x + dx[j]][y + dy[j]] = true;
						zeroCnt--;
						temp++;
					}
				}
			}
		}
		if (temp != 0 && temp == qx.size()) {
			day += temp / temp;
			temp = 0;
		}
	}
}