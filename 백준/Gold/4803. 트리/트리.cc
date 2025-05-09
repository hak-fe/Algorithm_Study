#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include<algorithm>
#define DEBUG 1
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)

using namespace std;
typedef long long int ll;

vector<vector<int>>graph(501, vector<int>(501));
vector<int> visited(501);
int isCycle = 0;

void dfs(int start, int size, int parent) {
	visited[start] = 1;
	for (int i = 1; i <= size; i++)
		if (graph[start][i] == 1) {
			if (!visited[i])
				dfs(i, size, start);
			else {
				if (parent != i)
					isCycle = 1;
			}
		}
}

int main() {
	FASTIO;
	int vertex, edge, start, end, cnt = 0, sequence = 1;
	while (1)
	{
		cin >> vertex >> edge;
		if (vertex == 0 && edge == 0)
			break;
		for (int i = 0; i < edge; i++)
		{
			cin >> start >> end;
			graph[start][end] = 1;
			graph[end][start] = 1;
		}
		for (int i = 1; i <= vertex; i++)
		{
			if (!visited[i]) {
				dfs(i, vertex, -1);
				if (!isCycle)
					cnt++;

			}
			isCycle = 0;
		}
		if (!cnt)
			cout << "Case " << sequence << ": No trees.\n";
		else if (cnt == 1)
			cout << "Case " << sequence << ": There is one tree.\n";
		else
			cout << "Case " << sequence << ": A forest of " << cnt << " trees.\n";

		graph.assign(501, vector<int>(501, 0));
		visited.assign(501, 0);
		cnt = 0;
		sequence++;
	}
	return 0;
}