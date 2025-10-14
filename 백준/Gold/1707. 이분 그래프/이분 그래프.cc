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
vector<int>visited;
bool isBiParGraph;
void bfs(int start);

int main() {
	FASTIO;
	int k;
	cin >> k;
	while (k--) {
		int v, e;
		cin >> v >> e;
		graph.assign(v + 1, vector<int>());
		visited.assign(v + 1, 0);
		
		for (int i = 0; i < e; i++)
		{
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		isBiParGraph = true;
		for (int i = 1; i <= v; i++)
			if(!visited[i])
				bfs(i);
		
		if (isBiParGraph)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}

void bfs(int start) {
	queue<int>q;
	q.push(start);
	visited[start] = 1; // 1과 2를 사용하여 두 집합으로 구분, 미방문의 값은 0
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (auto i : graph[v]) {
			if (visited[i]) {
				//방문한 정점이 현재 정점과 같은 visited값이면 이분 그래프가 아님
				if (visited[i] == visited[v]) {
					isBiParGraph = false;
					return;
				}
			}
			else {
				if (visited[v] == 1) {
					visited[i] = 2;
				}
				else {
					visited[i] = 1;
				}
				q.push(i);
			}
		}
	}
}