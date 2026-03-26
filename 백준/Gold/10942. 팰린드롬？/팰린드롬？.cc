#include<bits/stdc++.h>
using namespace std;

#define MAX 1000000
#define DIV 1000000007
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL)
#define endl '\n'

typedef unsigned long long ull;
typedef long long ll;

vector<int>seq;
vector<vector<short>>dp;

void f(int n) {

	for (int i = 1; i <= n; i++)
	{
		dp[i][i] = 1;
	}

	for (int i = 1; i < n; i++)
	{
		if (seq[i] == seq[i + 1]) {
			dp[i][i + 1] = 1;
		}
	}

	for (int i = 3; i <= n; i++)
	{
		for (int s = 1, e = i + s - 1; e <= n; s++, e++){
			if (seq[s] == seq[e] && dp[s + 1][e - 1])
				dp[s][e] = 1;
		}
	}
}

int main() {
	FASTIO;
	int n, m, s, e;
	cin >> n;
	seq.assign(n + 1, 0);
	dp.assign(n + 1, vector<short>(n + 1, 0));

	for (int i = 1; i <= n; i++)
	{
		cin >> seq[i];
	}
	f(n);
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> s >> e;
		cout << dp[s][e] << endl;
	}


	return 0;
}