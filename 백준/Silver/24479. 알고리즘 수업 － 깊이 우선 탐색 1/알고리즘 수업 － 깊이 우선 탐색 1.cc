#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long int ll;
int visited[100001]; // 방문확인용
int order[100001]; // 방문순서
void dfs(int start);
int cnt = 1;
vector<vector<int>>graph;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, r, s, e;
	cin >> n >> m >> r;
	graph.resize(n+1);
	for (int i = 0; i < m; i++)
	{
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}
	for (int i = 1; i <= n; i++)
		sort(graph[i].begin(), graph[i].end());
	dfs(r);
	for (int i = 1; i <= n; i++)
		cout << order[i] << '\n';
	return 0;
}
void dfs(int start) {
	visited[start] = 1;
	order[start] = cnt++;
	for (int i = 0; i < graph[start].size(); i++)
		if (visited[graph[start][i]] == 0)
			dfs(graph[start][i]);
}