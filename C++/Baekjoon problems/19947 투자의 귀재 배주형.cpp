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

int dp[11] = {};

int f(int m, int y)
{
	dp[0] = m;
	for (int i = 1; i <= y; i++)
	{
		dp[i] = dp[i - 1] * 1.05;
		if (i >= 3)
			dp[i] = max(dp[i], (int)(dp[i - 3] * 1.2));
		if (i >= 5)
			dp[i] = max(dp[i], (int)(dp[i - 5] * 1.35));
	}
	return dp[y];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int money;
	int year;
	cin >> money >> year;
	cout << f(money, year) << '\n';
}