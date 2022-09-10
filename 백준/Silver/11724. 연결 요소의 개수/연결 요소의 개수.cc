#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <deque>
#include <utility>

#define MIN 0
#define MAX 10000000

using namespace std;
typedef unsigned long long int ll;

vector<int>graph[1001]; //dfs
//int graph[1001][1001] = { 0, }; //bfs
bool visited[1001] = { false, };
int dx[4] = { 0, 1, 0, -1 }; //우, 하, 좌, 상 방향
int dy[4] = { 1, 0, -1, 0 };
int ans = 0;
void dfs(int x);
//int cnt = 0;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i])
			ans++;
		dfs(i);
	}
	cout << ans;
}
void dfs(int x) {
	visited[x] = true;
	for (int i = 0; i < graph[x].size(); i++)
	{
		int temp = graph[x][i];
		if (!visited[temp])
			dfs(temp);
	}
}