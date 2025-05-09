#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include<algorithm>
#define DEBUG 1
#define endl '\n'
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)

using namespace std;
typedef long long int ll;

vector<int>g(101); // 거리 저장
vector<int>visited(101);
vector<int>ledder(101);
vector<int>snake(101);

int bfs(int start) {
	queue<int>q;
	q.push(start);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 1; i <= 6; i++)
		{
			int next = cur + i, la, sn;
			if (next <= 100) { // 주사위로 방문 가능한 칸
				la = ledder[next], sn = snake[next];
				if (!visited[next]) {
					g[next] = g[cur] + 1;
					if (la != 0) {
						if (!visited[la]) {
							q.push(la);
							visited[la] = 1;
							g[la] = g[next];
						}
					}
					else if (sn != 0) {
						if (!visited[sn]) {
							q.push(sn);
							visited[sn] = 1;
							g[sn] = g[next];
						}
					}
					else {
						q.push(next);
						visited[next] = 1;
					}
				}
			}
		}
	}
	return g[100];
}

int main() {
	FASTIO;
	int n, m, s, e;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> e;
		ledder[s] = e;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> s >> e;
		snake[s] = e;
	}
	g[1] = 0;
	visited[1] = 1;
	cout << bfs(1) << endl;
	return 0;
}