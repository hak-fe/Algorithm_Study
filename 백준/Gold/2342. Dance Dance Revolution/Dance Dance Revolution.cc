#include<bits/stdc++.h>
using namespace std;

#define MAX 4
#define DIV 1000000007
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL)
#define endl '\n'

typedef unsigned long long ull;
typedef long long ll;


enum STEP { MID, UP, LEFT, DOWN, RIGHT };

int dp[100001][5][5];

int main() {
	FASTIO;

	int target, power = 10000000, i = 1;
	for (int s = 0; s < 100001; s++)
	{
		for (int k = 0; k <= MAX; k++)
		{
			for (int p = 0; p <= MAX; p++)
			{
				dp[s][k][p] = 10000000;
			}
		}
	}
	dp[0][0][0] = 0;
	while (1) {
		cin >> target;

		if (!target) 
			break;

		if (target == UP) {
			for (int j = 0; j <= MAX; j++)
			{
				if (target == j) continue;
				dp[i][target][j] =
					min(dp[i - 1][0][j] + 2
						, min(dp[i - 1][1][j] + 1
							, min(dp[i - 1][2][j] + 3
								, min(dp[i - 1][3][j] + 4
									, dp[i - 1][4][j] + 3))));

				dp[i][j][target] =
					min(dp[i - 1][j][0] + 2
						, min(dp[i - 1][j][1] + 1
							, min(dp[i - 1][j][2] + 3
								, min(dp[i - 1][j][4] + 3
									, dp[i - 1][j][3] + 4))));
			}

		}
		else if (target == LEFT) {
			for (int j = 0; j <= MAX; j++)
			{
				if (target == j) continue;
				dp[i][target][j] =
					min(dp[i - 1][0][j] + 2
						, min(dp[i - 1][1][j] + 3
							, min(dp[i - 1][2][j] + 1
								, min(dp[i - 1][3][j] + 3
									, dp[i - 1][4][j] + 4))));

				dp[i][j][target] =
					min(dp[i - 1][j][0] + 2
						, min(dp[i - 1][j][1] + 3
							, min(dp[i - 1][j][2] + 1
								, min(dp[i - 1][j][3] + 3
									, dp[i - 1][j][4] + 4))));
			}
		}
		else if (target == DOWN) {
			for (int j = 0; j <= MAX; j++)
			{
				if (target == j) continue;
				dp[i][target][j] =
					min(dp[i - 1][0][j] + 2
						, min(dp[i - 1][1][j] + 4
							, min(dp[i - 1][2][j] + 3
								, min(dp[i - 1][3][j] + 1
									, dp[i - 1][4][j] + 3))));

				dp[i][j][target] =
					min(dp[i - 1][j][0] + 2
						, min(dp[i - 1][j][1] + 4
							, min(dp[i - 1][j][2] + 3
								, min(dp[i - 1][j][3] + 1
									, dp[i - 1][j][4] + 3))));
			}
		}
		else {
			for (int j = 0; j <= MAX; j++)
			{
				if (target == j) continue;
				dp[i][target][j] =
					min(dp[i - 1][0][j] + 2
						, min(dp[i - 1][1][j] + 3
							, min(dp[i - 1][2][j] + 4
								, min(dp[i - 1][3][j] + 3
									, dp[i - 1][4][j] + 1))));

				dp[i][j][target] =
					min(dp[i - 1][j][0] + 2
						, min(dp[i - 1][j][1] + 3
							, min(dp[i - 1][j][2] + 4
								, min(dp[i - 1][j][3] + 3
									, dp[i - 1][j][4] + 1))));
			}
		}
		i++;
	}

	for (int k = 0; k <= MAX; k++)
	{
		for (int p = 0; p <= MAX; p++)
		{
			power = min(dp[i - 1][k][p], power);
		}
	}
	cout << power;

	return 0;
}