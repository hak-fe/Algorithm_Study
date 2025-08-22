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
int item[501][501];
int dp[501][501];
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, res;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			cin >> item[i][j];

	//dp[a][b] 의 의미 : a,b 에서의 최대값

	dp[1][1] = item[1][1]; //맨 윗부분은 item[1][1]과 같음
	res = item[1][1];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++)
		{
			//dp[i][1]은 대각선 오른쪽 위 계산 한 번만 해준다.
			if (j == 1)
				dp[i][j] = item[i][j] + dp[i - 1][j];
			//dp[i][j](i == j)는 대각선 왼쪽 위 계산 한 번만 해준다.
			else if (i == j)
				dp[i][j] = item[i][j] + dp[i - 1][j - 1];
			//그 이외의 경우는 대각선 왼쪽, 오른쪽 두 번 해준다. max 사용
			else
				dp[i][j] = max(item[i][j] + dp[i - 1][j],
					item[i][j] + dp[i - 1][j - 1]);
			res = max(res, dp[i][j]);
		}
	}
	cout << res;
}