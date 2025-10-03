#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>

#define DEBUG 0
#define endl '\n'
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)
#define DIV 10007
#define INF 2100000000
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int dz[2] = { 1, -1 };

vector<vector<pair<int, int>>>graph;
vector<int>dist;
struct cmp {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return a.second > b.second;
		// 거리(second)가 작은 게 우선순위 높도록 (min-heap)
	}
};
void djikstra(int start);

int main() {
	
	int v, e, k, start, end, weight;
	cin >> v >> e >> k;
	graph.assign(v + 1, vector<pair<int,int>>());
	for (int i = 0; i < e; i++)
	{
		cin >> start >> end >> weight;
		graph[start].push_back(make_pair(end, weight));
	}

	dist.assign(v + 1, INF);
	dist[k] = 0;

	djikstra(k);

	for (int i = 1; i <= v; i++)
	{
		if (dist[i] == INF)
			cout << "INF" << endl;
		else
			cout << dist[i] << endl;
	}

	return 0;

}
void djikstra(int start){
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	pq.push({ start, 0 });

	while (!pq.empty()) {
		int cur_vertex = pq.top().first; // 현재 정점
		int cur_dist = pq.top().second; // 현재 정점까지의 누적 거리
		pq.pop();

		if (dist[cur_vertex] < cur_dist)
			continue;

		for (int i = 0; i < graph[cur_vertex].size(); i++)
		{
			int next_vertex = graph[cur_vertex][i].first;
			int next_dist = graph[cur_vertex][i].second;

			if (cur_dist + next_dist < dist[next_vertex])
			{
				dist[next_vertex] = cur_dist + next_dist;
				pq.push({ next_vertex, cur_dist + next_dist });
			}
		}
	}
}