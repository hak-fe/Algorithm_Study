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

long long int dp[1001] = {};

long long int square(int n) 
{
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] % 10007 + dp[i - 2] % 10007;
	}
	return dp[n] % 10007;
}

int main()
{
	int n;
	cin >> n;
	cout << square(n);
}