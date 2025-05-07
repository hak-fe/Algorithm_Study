#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include<algorithm>
#define DEBUG 1
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)
#define DIV 1000000000
using namespace std; 
typedef long long int ll;

ll dp[101][10];

int main() {
	FASTIO;
	int n;
	ll sum = 0;
	cin >> n;

	for (int i = 1; i <= 9; i++)
	{
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = dp[i - 1][1] % DIV;
		dp[i][9] = dp[i - 1][8] % DIV;
		for (int j = 1; j <= 8; j++)
		{
			dp[i][j] = dp[i - 1][j - 1] % DIV + dp[i - 1][j + 1] % DIV;
			dp[i][j] %= DIV;
		}
	}
	for (int i = 0; i <= 9; i++)
	{
		sum += dp[n][i];
	}
	cout << sum % DIV;
	return 0;
}