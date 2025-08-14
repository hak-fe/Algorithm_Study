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
vector<vector<int>>result;

void bfs(int size);

int main() {
	FASTIO;
	int n;
	cin >> n;

	graph.assign(n, vector<int>());
	result.assign(n, vector<int>(n, 0));
	visited.assign(n, 0);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0, temp; j < n; j++)
		{
			cin >> temp;
			if (temp)
				graph[i].push_back(j);
		}
	}
	bfs(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			cout << result[i][j] << ' ';
		}
		cout << endl;
	}
}

void bfs(int size) {
	for (int i = 0; i < size; i++)
	{
		visited.assign(size, 0);
		queue<int>q;
		q.push(i);
		while (!q.empty()) {
			int s = q.front();
			q.pop();
			for (int j = 0; j < graph[s].size(); j++)
			{
				if (!visited[graph[s][j]]) {
					visited[graph[s][j]] = 1;
					result[i][graph[s][j]] = 1;
					q.push(graph[s][j]);
				}
			}
		}
	}
}