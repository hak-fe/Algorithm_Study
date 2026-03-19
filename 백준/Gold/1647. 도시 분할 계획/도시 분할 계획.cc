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

ll max(ll a, ll b) { return (a > b ? a : b); }

vector<tuple<int, int, int>>graph;
vector<int>parent;
vector<int>rnk;

int find(int a) {
	if (parent[a] == a)
		return a;
	return parent[a] = find(parent[a]);
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	if (rnk[x] < rnk[y]) swap(x, y);
	parent[y] = x;
	if (rnk[x] == rnk[y]) rnk[x]++;
}

int main() {
	FASTIO;
	ll sum = 0, maxWeight = 0;
	int n, m, a, b, c;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		graph.push_back({ c,a,b });
	}
	parent.assign(n + 1, 0);
	rnk.assign(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}

	sort(graph.begin(), graph.end());

	for (int i = 0; i < m; i++)
	{
		int a = get<1>(graph[i]), b = get<2>(graph[i]), c = get<0>(graph[i]);
		if (find(a) != find(b)) {
			unite(a, b);
			maxWeight = max(maxWeight, get<0>(graph[i]));
			sum += get<0>(graph[i]);
		}
	}
	cout << sum - maxWeight;

	return 0;
}