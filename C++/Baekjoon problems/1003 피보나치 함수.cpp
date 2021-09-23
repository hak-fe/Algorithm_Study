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

ll dp[41][2] = {}; // n번 째의 피보나치 수에 0과 1이 얼마나 들었는지 저장하는 배열

void DP(int n)
{
	for (int i = 2; i <= 40; i++)
	{
		dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
		dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
	}
}

int main()
{
	dp[0][0] = 1;
	dp[0][1] = 0;
	dp[1][0] = 0;
	dp[1][1] = 1;

	int testcase, n;
	cin >> testcase;
	DP(40);
	while (testcase--)
	{
		cin >> n;
		cout << dp[n][0] << ' ' << dp[n][1] << '\n';
	}
}