#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#include <stdlib.h>

#define DEBUG 0
#define endl '\n'
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)
#define DIV 10000
#define MAX 10001
#define INF 2100000000
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int dz[2] = { 1, -1 };

vector<vector<pair<int,int>>>v;
vector<int>dist;

void djikstra(int start, int end);

int main() {
	FASTIO;
	int n, m, s, e, w;
	cin >> n >> m;
	v.assign(n + 1, vector<pair<int, int>>());
	dist.assign(n + 1, INF);

	for (int i = 0; i < m; i++)
	{
		cin >> s >> e >> w;
		v[s].push_back({ e, w });
	}
	cin >> s >> e;
	djikstra(s, e);

	return 0;
}
void djikstra(int start, int end) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

	pq.push({ start, 0 });

	while (!pq.empty()) {
		int cur_vertex = pq.top().first, cur_weight = pq.top().second;
		pq.pop();

		if (dist[cur_vertex] < cur_weight)
			continue;

		for (auto i : v[cur_vertex]) {
			int next_vertex = i.first, next_weight = i.second;
			if (dist[next_vertex] > cur_weight + next_weight) {
				dist[next_vertex] = cur_weight + next_weight;
				pq.push({ next_vertex, dist[next_vertex] });
			}
		}
	}
	cout << dist[end];
}