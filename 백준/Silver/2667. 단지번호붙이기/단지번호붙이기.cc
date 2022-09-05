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

int graph[26][26];
bool visited[26][26] = { false, };
int dx[4] = { 0, 1, 0, -1 }; //우, 하, 좌, 상 방향
int dy[4] = { 1, 0, -1, 0 };
vector<int>ans;

int n;

void bfs(int x, int y);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> str;
		for (int j = 0; j < n; j++)
		{
			graph[i + 1][j + 1] = str[j] - '0';
		}
	}
	bfs(1, 1);
}
void bfs(int startX, int startY) {
	int cnt = 0;
	queue<int>qx;
	queue<int>qy;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (visited[i][j] || graph[i][j] == 0)
				continue;
			else {
				cnt++;
				qx.push(i);
				qy.push(j);
				while (!qx.empty() && !qy.empty())
				{
					int x = qx.front();
					int y = qy.front();
					visited[x][y] = true;
					qx.pop();
					qy.pop();
					for (int i = 0; i < 4; i++)
					{
						if (!visited[x + dx[i]][y + dy[i]] && graph[x + dx[i]][y + dy[i]] == 1) {
							qx.push(x + dx[i]);
							qy.push(y + dy[i]);
							visited[x + dx[i]][y + dy[i]] = true;
							cnt++;
						}
					}
				}
				if(cnt != 0)
					ans.push_back(cnt);
				cnt = 0;
			}

		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';
}