#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 100001
#define DIV 1000000007
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL)
#define endl '\n'

typedef unsigned long long ull;
typedef long long ll;
vector<vector<int>>tree;
vector<int>dp;

void dfs(int current, int parent) {
	//cout << "current : " << current << endl;
	//cout << "parent : " << parent << endl;

	for (int nextNode : tree[current]) {
		//cout << "nextNode : " << nextNode << endl;
		if (nextNode == parent) continue;
		//	cout << "nextNode != current, dfs(" << nextNode << ", " << current << ") 실시" << endl;
		dfs(nextNode, current);
		dp[current] += dp[nextNode];
	}

	return;
}
int main() {
	FASTIO;
	int n, r, q, u, v, query;
	cin >> n >> r >> q;
	tree.assign(n + 1, vector<int>());
	dp.assign(n + 1, 1);
	for (int i = 0; i < n - 1; i++)
	{
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	dfs(r, -1); // 첫 시작은 r 부터, r의 부모는 없으므로 -1로 두기

	for (int i = 0; i < q; i++)
	{
		cin >> query;
		cout << dp[query] << endl;
	}

	return 0;
}