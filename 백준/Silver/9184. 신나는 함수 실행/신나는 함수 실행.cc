#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>

#define DEBUG 1
#define endl '\n'
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)

using namespace std;
typedef long long int ll;
int dp[21][21][21];
void func() {

	for (int i = 0; i <= 20; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			for (int k = 0; k <= 20; k++)
			{
				if (i <= 0 || j <= 0 || k <= 0)
					dp[i][j][k] = 1;
				else if (i < j && j < k)
					dp[i][j][k] =
					dp[i][j][k - 1] +
					dp[i][j - 1][k - 1] -
					dp[i][j - 1][k];

				else
					dp[i][j][k] =
					dp[i - 1][j][k] +
					dp[i - 1][j - 1][k] +
					dp[i - 1][j][k - 1] -
					dp[i - 1][j - 1][k - 1];
			}
		}
	}
}

int main() {

	func();

	int a, b, c;
	while (1) {
		cin >> a >> b >> c;

		if (a == -1 && b == -1 && c == -1)
			break;

		if (a <= 0 || b <= 0 || c <= 0)
			cout << "w(" << a << ", " << b << ", " << c << ") = "
			<< 1 << endl;
		else if (a > 20 || b > 20 || c > 20)
			cout << "w(" << a << ", " << b << ", " << c << ") = "
			<< dp[20][20][20] << endl;
		else
			cout << "w(" << a << ", " << b << ", " << c << ") = "
			<< dp[a][b][c] << endl;
	}
	return 0;
}