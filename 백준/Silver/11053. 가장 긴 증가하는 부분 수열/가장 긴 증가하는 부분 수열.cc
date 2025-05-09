#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <deque>

#define MIN 2147483647;
#define MAX 0; 

using namespace std;
typedef unsigned long long int ll;
int item[1001];
int dp[1001];
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, res = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> item[i];
		dp[i] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (item[i] > item[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		res = max(res, dp[i]);
	}
	cout << res;
}