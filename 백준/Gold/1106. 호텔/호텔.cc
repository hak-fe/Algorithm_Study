#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 2100000000
#define DIV 1000000007
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL)
#define endl '\n'

typedef unsigned long long ull;
typedef long long ll;
int dp[21][1001]; // i번째 도시 까지 고려할 때, 
// 늘리려는 사람이 적어도 j명인 경우 홍보 비용의 최솟값
vector<int>cost;
vector<int>customer;
int main() {
	FASTIO;
	int c, n;
	cin >> c >> n;
	cost.assign(n + 1, 0);
	customer.assign(n + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> cost[i] >> customer[i];

	for (int i = 1; i <= c; i++)
			dp[0][i] = MAX;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= c; j++) {
			
				dp[i][j] = min(dp[i - 1][j], dp[i][max(0, j - customer[i])] + cost[i]);
			
		}
	}
	cout << dp[n][c];
	return 0;
}