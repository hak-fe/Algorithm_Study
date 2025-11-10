#include<iostream>
#include <vector>
using namespace std;

#define MAX 100000
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL), cin.tie(NULL)
#define endl '\n'
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector<int>uni;
vector<int>ranking;

int find(int i) {
	if (uni[i] == i)
		return i;
	return uni[i] = find(uni[i]);
}
void unite(int a, int b) {
	// 합집합 구현
	int ra = find(a);
	int rb = find(b);
	if (ra != rb) {
		if (ranking[ra] < ranking[rb])
			uni[ra] = rb;
		else if (ranking[ra] > ranking[rb])
			uni[rb] = ra;
		else {
			uni[rb] = ra;
			ranking[ra]++;
		}
	}
}
int main() {
	FASTIO;
	int n, m, a, b, c;
	cin >> n >> m;
	uni.assign(n + 1, 0);
	ranking.assign(n + 1, 0);
	for (int i = 0; i <= n; i++) {
		uni[i] = i;
		ranking[i] = 0;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		if (a) {
			if (find(b) == find(c))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		else {
			unite(b, c);
		}
	}
	return 0;
}