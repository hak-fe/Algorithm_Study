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
vector<ll>visitedOrder; // 방문 순서
vector<ll>visitedDepth; // 방문 노드의 깊이
void bfs(int start);

int main() {
	FASTIO;
	ll n, m, r, sum = 0;
	cin >> n >> m >> r;
	graph.assign(n + 1, vector<int>());
	visitedDepth.assign(n + 1, -1);
	visitedOrder.assign(n + 1, INF);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	bfs(r);

	for (int i = 1; i <= n; i++)
	{
		if (visitedOrder[i] == INF)
			continue;
		sum += visitedDepth[i] * visitedOrder[i];
	}
	cout << sum;
	return 0;
}

void bfs(int start) {
	int cnt = 0;
	queue<int>q;
	q.push(start);
	visitedDepth[start] = 0;
	visitedOrder[start] = ++cnt;
	while (!q.empty()) {
		int n = q.front();
		q.pop();
		for (auto i : graph[n]) {
			if (visitedOrder[i] == INF) {
				visitedOrder[i] = ++cnt;
				visitedDepth[i] = visitedDepth[n] + 1;
				q.push(i);
			}
		}
	}
	
}