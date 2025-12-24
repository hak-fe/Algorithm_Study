#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 100000
#define DIV 1000000007
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL)
#define endl '\n'

typedef unsigned long long ull;
typedef long long ll;

vector<vector<pair<int, int>>> g;
ll dist[MAX + 1];
int visited[MAX + 1];
pair<int, ll> maxInfo(-1, -1);
void dfs(int start) {
	visited[start] = 1;
	for (int i = 0; i < g[start].size(); i++)
	{
		int e = g[start][i].first, w = g[start][i].second;
		if (!visited[e]) {
			dist[e] = dist[start] + w;
			if (dist[e] > maxInfo.second) {
				maxInfo.first = e;
				maxInfo.second = dist[e];
			}
			dfs(e);
		}
	}
}
int main() {
	FASTIO;
	int n;
	cin >> n;
	
	g.assign(n + 1, vector<pair<int, int>>());
	for (int i = 0; i < n; i++)
	{
		int v;
		cin >> v;
		while (1) {
			int e, w;
			cin >> e;
			if (e != -1) {
				cin >> w;
				g[v].push_back(make_pair(e, w));

			}
			else
				break;
		}
	}

	dfs(1);
	
	memset(dist, 0, sizeof(dist));
	memset(visited, 0, sizeof(visited));
	maxInfo.second = -1;

	dfs(maxInfo.first);
	cout << maxInfo.second;
	return 0;
}