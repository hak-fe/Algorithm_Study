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
#define MAX 10001

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int dz[2] = { 1, -1 };

short input[2][100000];
int dp[2][100000]; // n열에서의 최댓값

int main() {
	FASTIO;
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < n; j++) {
				cin >> input[i][j];
			}
		}

		dp[0][0] = input[0][0];
		dp[1][0] = input[1][0];

		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				if (j == 0)
					dp[j][i] = max(dp[j][i - 1], dp[j + 1][i - 1] + input[j][i]);
				else
					dp[j][i] = max(dp[j][i - 1], dp[j - 1][i - 1] + input[j][i]);
			}
		}
		cout << max(dp[0][n - 1], dp[1][n - 1]) << endl;
	}
}
