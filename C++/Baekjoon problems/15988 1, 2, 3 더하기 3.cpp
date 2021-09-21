#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
typedef unsigned long long int ll;

ll dp[1000001] = {};

ll DP(int n) {
	for (int i = 4; i <= n; i++)
	{
		dp[i] = dp[i - 1] % 1000000009 + dp[i - 2] % 1000000009 + dp[i - 3] % 1000000009;
	}
	return dp[n] % 1000000009;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, temp;
	cin >> n;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	while (n--)
	{
		cin >> temp;
		cout << DP(temp) >> '\n';
	}
}