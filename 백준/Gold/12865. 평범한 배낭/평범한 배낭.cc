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

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int dp[101][100001]; // i번째 물건까지 확인했을 때, 

vector<int>weight;
vector<int>value;

int main() {
	FASTIO;
	int n, k, w, v;
	cin >> n >> k;

	weight.push_back(0);
	value.push_back(0);

	for (int i = 0; i < n; i++)
	{
		cin >> w >> v;
		weight.push_back(w);
		value.push_back(v);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			int temp = j - weight[i];
			if (temp >= 0)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][temp] + value[i]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	
	cout << dp[n][k];

	return 0;
}