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

vector<vector<int>>graph;
vector<int>visited;

void bfs(int start);

int main() {
	FASTIO;
	int n, m, cnt = 0;
	cin >> n >> m;
	graph.assign(n + 1, vector<int>());
	visited.assign(n + 1, 0);
	
	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}
	
	bfs(1);
	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == 2 || visited[i] == 3)
			cnt++;
	}
	cout << cnt;
	return 0;
}

void bfs(int start) {
	queue<int>q;
	q.push(start);
	visited[start] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (auto i : graph[x]) {
			if (!visited[i]) {
				visited[i] = visited[x] + 1;
				q.push(i);
			}
		}
	}
}