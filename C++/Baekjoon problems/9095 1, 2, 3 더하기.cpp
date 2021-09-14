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

int dp[11] = {};

int DP(int n) {
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	return dp[n];
}

int main()
{
	int testcase, n;
	cin >> testcase;
	while (testcase--)
	{
		cin >> n;
		cout << DP(n) << '\n';
	}
}