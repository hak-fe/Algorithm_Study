#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#include <stdlib.h>

#define DEBUG 0
#define endl '\n'
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)
#define DIV 10000
#define MAX 100001
#define INF 2100000000
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int dz[2] = { 1, -1 };

vector<vector<int>> v;
int dp[17][17][3];

void getCaseNum(int size);

int main() {
	FASTIO;
	int n;
	cin >> n;
	v.assign(n + 1, vector<int>(n + 1));


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> v[i][j];
		}
	}
	dp[1][2][0] = 1;
	getCaseNum(n);
	cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
	return 0;
}

void getCaseNum(int size) {
	for (int i = 1; i <= size; i++)
	{
		for (int j = 3; j <= size; j++)
		{
			//가로의 경우
			if (v[i][j] == 0) {
				dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2];
			}
			//세로의 경우
			if (v[i][j] == 0) {
				dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2];
			}
			//대각선의 경우
			if (v[i][j] == 0 && v[i - 1][j] == 0 && v[i][j - 1] == 0) {
				dp[i][j][2] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
			}
		}
	}
}