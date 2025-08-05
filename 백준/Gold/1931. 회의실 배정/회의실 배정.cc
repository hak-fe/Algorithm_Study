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

vector<pair<int, int>>v;

bool comparePairs(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second != b.second)
		return a.second < b.second;

	return a.first < b.first;
}

int main() {
	FASTIO;
	int n, a, b, cnt = 1;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}

	sort(v.begin(), v.end(), comparePairs);

	a = v[0].first, b = v[0].second;

	for (int i = 1; i < n; i++)
	{
		int ta = v[i].first, tb = v[i].second;
		if (ta >= b) {
			a = ta;
			b = tb;
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}