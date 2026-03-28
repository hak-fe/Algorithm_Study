#include<bits/stdc++.h>
using namespace std;

#define MAX 2100000000
#define DIV 1000000007
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL)
#define endl '\n'

typedef unsigned long long ull;
typedef long long ll;

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
	int n, m, a, b, res = MAX;
	cin >> n >> m;
	parent.assign(n, 0);
	rnk.assign(n, 0);

	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		if (find(a) == find(b)) {
			res = min(res, i+1);
		}
		else
			unite(a, b);
	}
	if (res == MAX)
		cout << 0;
	else
		cout << res;
	return 0;
}