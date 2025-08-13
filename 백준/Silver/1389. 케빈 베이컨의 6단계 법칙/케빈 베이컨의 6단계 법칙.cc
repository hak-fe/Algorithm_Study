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
#define MAX 2001

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int dz[2] = { 1, -1 };
vector<vector<int>>graph;
vector<int>visited;
vector<int>kevinCnt;

void bfs(int size);
int getLowerNum(int size);

int main() {
	FASTIO;
	int n, m;
	cin >> n >> m;

	graph.assign(n + 1, vector<int>());
	kevinCnt.assign(n + 1, 0);

	for (int i = 0, a, b; i < m; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	bfs(n);

	cout << getLowerNum(n);
}
void bfs(int size) {
	for (int i = 1; i <= size; i++)
	{
		visited.assign(size + 1, 0);
		int sum = 0;
		queue<int>q;
		q.push(i);
		visited[i] = 1;
		while (!q.empty()) {
			int s = q.front();
			q.pop();
			for (int j = 0; j < graph[s].size(); j++)
			{
				if (!visited[graph[s][j]]) {
					visited[graph[s][j]] = visited[s] + 1;
					sum += visited[graph[s][j]] - 1;
					q.push(graph[s][j]);
				}
			}
		}
		kevinCnt[i] = sum;
	}
}
int getLowerNum(int size) {
	int min = kevinCnt[1], idx = 1;
	for (int i = 2; i <= size; i++)
	{
		if (kevinCnt[i] < min) {
			min = kevinCnt[i];
			idx = i;
		}
	}
	return idx;
}