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

ll dp[10000001] = {};

ll F(int n)
{
	dp[1] = 1;
	dp[2] = 2; 
	dp[3] = 3; 
	for (int i = 4; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10;
	}
	return dp[n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	cout << F(n) << '\n';
}