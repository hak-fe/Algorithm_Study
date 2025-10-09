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
vector<vector<int>>v;
vector<int> visited;
void bfs(int start);

int main() {
	FASTIO;
	int n, m, k, x, isExisted = 0;
	cin >> n >> m >> k >> x;
	v.assign(n + 1, vector<int>());
	visited.assign(n + 1 , -1);
	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;
		v[s].push_back(e);
	}
	bfs(x);
	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == k) {
			isExisted = 1;
			cout << i << endl;
		}
	}
	if(!isExisted)
		cout << -1 << endl;
	return 0;
}
void bfs(int start) {
	queue<int>q;
	q.push(start);
	visited[start] = 0;
	while (!q.empty()) {
		int cur_vertex = q.front();
		q.pop();

		for (int next_vertex : v[cur_vertex]) {
			if (visited[next_vertex] == -1) {
				visited[next_vertex] = visited[cur_vertex] + 1;
				q.push(next_vertex);
			}
		}
	}
}