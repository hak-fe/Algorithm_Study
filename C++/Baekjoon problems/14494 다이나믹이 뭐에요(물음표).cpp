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

 ll dp[1001][1001] = {};

 ll DP(int n, int m) {
	 for (int i = 2; i <= max(n, m); i++)
	 {
		 for (int j = 2; j <= max(n, m); j++)
		 {
			 dp[i][j] = dp[i - 1][j] % 1000000007 + dp[i][j - 1] % 1000000007 + dp[i-1][j-1] % 1000000007;
		 }
	 }
	 return dp[n][m] % 1000000007;
 }

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= max(n,m); i++)
	{
		dp[1][i] = 1;
		dp[i][1] = 1;
	}
	cout << DP(n, m);
}