#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 10000
#define DIV 1000000007
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL)
#define endl '\n'

typedef unsigned long long ull;
typedef long long ll;

vector<vector<pair<int, ll>>>g;
int visited[MAX + 1];
ll dist[MAX + 1];
pair<int, ll> maxInfo(1, 0);
void dfs(int start);

int main() {
	FASTIO;
	
	int n;
	cin >> n;
	g.assign(MAX + 1, vector<pair<int, ll>>());
	for (int i = 0; i < n - 1; i++)
	{
		int s, e, w;
		cin >> s >> e >> w;
		g[s].push_back(make_pair(e, w));
		g[e].push_back(make_pair(s, w));

	}
	
	dfs(1);
	
	memset(visited, 0, sizeof(visited));
	memset(dist, 0, sizeof(dist));

	dfs(maxInfo.first);

	cout << maxInfo.second;

	return 0;
}
void dfs(int start) {
	visited[start] = 1;
	for (int i = 0; i < g[start].size(); i++) {
		int next = g[start][i].first, weight = g[start][i].second;
		if (!visited[next]) {
			dist[next] = dist[start] + weight;
			if (dist[next] > maxInfo.second) {
				maxInfo.first = next;
				maxInfo.second = dist[next];
			}
			dfs(next);
		}
	}
}