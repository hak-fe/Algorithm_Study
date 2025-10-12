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
vector<pair<int, int>>temp;
vector<int>visited;
void bfs(int start);
int main() {
	FASTIO;
	int n, m, r;
	cin >> n >> m >> r;
	graph.assign(n + 1, vector<int>());
	visited.assign(n + 1, 0);
	
	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;
		temp.push_back({ s, e });
	}
	sort(temp.begin(), temp.end());

	for (int i = 0; i < m; i++)
	{
		graph[temp[i].first].push_back(temp[i].second);
		graph[temp[i].second].push_back(temp[i].first);
	}
	bfs(r);
	for (int i = 1; i <= n; i++)
	{
		cout << visited[i] << endl;
	}
	return 0;
}

void bfs(int start) {
	int order = 1;
	queue<int>q;
	q.push(start);
	visited[start] = order++;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (auto i : graph[x]) {
			if (!visited[i]) {
				visited[i] = order++;
				q.push(i);
			}
		}
	}
}