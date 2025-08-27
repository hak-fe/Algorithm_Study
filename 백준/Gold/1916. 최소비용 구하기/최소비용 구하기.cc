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
#define MAX 2100000000
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int dz[2] = { 1, -1 };
int res = -1;
vector<vector<pair<ll, ll>>>v; // 버스의 출발, 도착점, 가중치 저장
vector<ll>dist; // 최단거리 저장

void djikstra(int start, int end);

int main() {
	int n, m, s, e, w;
	cin >> n >> m;
	v.assign(n + 1, vector<pair<ll, ll>>());
	dist.assign(n + 1, MAX);

	for (int i = 0; i < m; i++)
	{
		cin >> s >> e >> w;
		v[s].push_back(make_pair(w, e)); //시작, 출발, 가중치 입력받기
	}

	cin >> s >> e;
	djikstra(s, e);

	return 0;

}
void djikstra(int start, int end){
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>pq;
	
	dist[start] = 0;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		ll cur_weight = pq.top().first, cur_vertex = pq.top().second;
		pq.pop();

		if (dist[cur_vertex] < cur_weight)
			continue;

		for (int i = 0; i < v[cur_vertex].size(); i++)
		{
			ll next_weight = v[cur_vertex][i].first, next_vertex = v[cur_vertex][i].second;
			if (dist[next_vertex] > cur_weight + next_weight) {
				dist[next_vertex] = cur_weight + next_weight;
				pq.push(make_pair(dist[next_vertex], next_vertex));
			}
		}
	}
	cout << dist[end];
}