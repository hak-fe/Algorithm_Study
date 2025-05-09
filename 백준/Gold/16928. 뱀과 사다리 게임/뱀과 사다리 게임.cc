#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include<algorithm>
#define DEBUG 0
#define endl '\n'
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)

using namespace std;
typedef long long int ll;

/*
g[1] == 0
g[2]부터 시작.
1. 거리 판단
2. 사다리 or 뱀 여부

2~7 을 큐1에 푸쉬
2~7 방문처리
2~7에 값 1 넣어주고
2~7에서 미방문이면서,
1) 주사위로 갈 수 있는 칸을 조사하여 거리 +1 넣어주기, 방문처리
2) 사다리 또는 뱀이 있다면 그것들을 타고 넘어간 칸에도 +1 해주기, 방문처리
1, 2가 제대로 동작한 칸은 큐1에 저장 (일단 큐 1개만으로 짜보자)

*사다리나 뱀이 있는 칸을 n이라고 할 때, n은 큐에 넣으면 안된다. 사다리나 뱀 타고 간 칸을 넣어야 한다.
**사다리나 뱀을 처음 탔을 떄는 큐에 넣으나 2회 이상은 넣지 않는다.
100에 처음 도달하면 끝내기
*/

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
							if (DEBUG) cout << la << "push" << endl;
							visited[la] = 1;
							g[la] = g[next];
						}
					}
					else if (sn != 0) {
						if (!visited[sn]) {
							q.push(sn);
							if (DEBUG) cout << sn << "push" << endl;
							visited[sn] = 1;
							g[sn] = g[next];
						}
					}
					else {
						q.push(next);
							if (DEBUG) cout << next << "push" << endl;
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