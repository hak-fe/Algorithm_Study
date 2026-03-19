#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include<tuple>
using namespace std;

#define MAX 1000000000
#define DIV 1000000007
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL)
#define endl '\n'

typedef unsigned long long ull;
typedef long long ll;

vector<tuple<int, int, int>>graph;
vector<int>parent;
vector<int>rnk;

int find(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	if (rnk[x] < rnk[y]) // 낮은 트리를 높은 트리 밑에 붙인다.
		swap(x, y);
	parent[y] = x;
	if (rnk[x] == rnk[y]) rnk[x]++;
}


int main() {
	FASTIO;
	ll sum = 0;
	int v, e, a, b, c;
	cin >> v >> e;

	for (int i = 0; i < e; i++)
	{
		cin >> a >> b >> c;
		graph.push_back({ c, a, b });
	}
	parent.assign(v + 1, 0);
	rnk.assign(v + 1, 0);
	for (int i = 1; i <= v; i++)
	{
		parent[i] = i;
	}
	sort(graph.begin(), graph.end());

	for (int i = 0; i < e; i++)
	{
		if (find(get<1>(graph[i])) != find(get<2>(graph[i]))) {
			unite(get<1>(graph[i]), get<2>(graph[i]));
			sum += get<0>(graph[i]);
		}
	}
	cout << sum;
	return 0;
}