#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>

#define DEBUG 1
#define endl '\n'
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)
#define DIV 10007
#define MAX 2001
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

queue<int>q;
vector<vector<int>>graph;
vector<int>indegree;
vector<int>res;
vector<int>check;
int main() {
	int n, m, s, e;
	cin >> n >> m;

	graph.assign(n + 1, vector<int>(0, 0));
	indegree.assign(n + 1, 0);

	for (int i = 1; i <= m; i++)
	{
		cin >> s >> e;
		graph[s].push_back(e);
		indegree[e]++;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!indegree[i])
			q.push(i);
	}

	for (int i = 1; i <= n; i++)
	{

		int v = q.front();
		res.push_back(v);
		if (q.empty()) break;
		q.pop();

		for (int j = 0; j < graph[v].size(); j++)
		{
			indegree[graph[v][j]]--;
			if (!indegree[graph[v][j]])
				q.push(graph[v][j]);
		}

	}
	check.assign(n + 1, 1);

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << ' ';
		check[res[i]] = 0;
	}
	/*for (int i = 1; i <= n; i++)
	{
		if (check[i])
			cout << i << ' ';
	}*/

	return 0;
}

