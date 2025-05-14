#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#include <tuple>

#define DEBUG 0
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)
#define endl '\n'
using namespace std;
typedef long long int ll;

int num[1001];
int dp[1001];
vector<int> temp;
int main() {
	FASTIO;
	int n, res = 0, idx = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> num[i];
		dp[i] = 1;
	}
	// 4 1 2 3 5
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++) {
			if (num[i] > num[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		if (dp[i] > res) {
			res = dp[i];
			idx = i;
		}
	}
	temp.push_back(idx); 
	
	for (int i = idx - 1; i >= 1 ; i--)
	{
		if (num[i] < num[temp[temp.size() - 1]] && dp[i] + 1 == dp[temp[temp.size()-1]]) {
			temp.push_back(i);
		}
	}
	cout << res << endl;
	for (int i = temp.size() - 1; i >= 0; i--)
	{
		cout << num[temp[i]] << ' ';
	}

	return 0;
}