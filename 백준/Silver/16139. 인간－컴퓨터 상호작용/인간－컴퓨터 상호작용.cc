#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include<algorithm>
#define DEBUG 1
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)

using namespace std;
typedef long long int ll;

int dp[200000][26];

int main() {
	FASTIO;
	char ch;
	string str;
	int n, left, right, len;
	cin >> str >> n;
	len = str.length();
	dp[0][str[0] - 'a']++;
	for (int i = 1; i < len; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			dp[i][j] = dp[i - 1][j];
		}
		dp[i][str[i] - 'a']++;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> ch >> left >> right;
		if (left == 0)
			cout << dp[right][ch - 'a'] << '\n';
		else
			cout << dp[right][ch - 'a'] - dp[left - 1][ch - 'a'] << '\n';
	}

	return 0;
}