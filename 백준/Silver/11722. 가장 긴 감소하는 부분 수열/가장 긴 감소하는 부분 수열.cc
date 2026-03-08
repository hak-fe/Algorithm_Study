#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 10000
#define DIV 1000000007
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL)
#define endl '\n'

typedef unsigned long long ull;
typedef long long ll;

void solve(vector<int>&arr, vector<int>& dp) {
	int res = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < i; j++) {
			if (arr[i] < arr[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		res = max(res, dp[i]);
	}
	cout << res;
}

int main() {
	FASTIO;
	int n;
	cin >> n;
	vector<int>arr(n);
	vector<int>dp(n, 1);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	solve(arr, dp);
	return 0;
}