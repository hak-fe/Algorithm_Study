#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

int dp[1001]; // 장당 카드 값을 입력받을 배열
int maxnum[1001] = {}; // n개를 구매했을 때, 최대값을 저장하는 배열

int DP(int n) 
{
	maxnum[0] = 0; // 0개는 0원
	for (int i = 1; i <= n; i++) 
	// 1부터 n개 까지 반복한다.
	{
		for (int j = 1; j <= i; j++)
		// 1부터 i 까지 반복한다. 1은 경우가 1개, 2는 경우가 2개, 3은 경우가 3개 ... 이기 때문
		{
			maxnum[i] = max(maxnum[i], maxnum[i - j] + dp[j]);
		}
	}
	return maxnum[n];
}

int main()
{
	int n;
	cin >> n; 
	for (int i = 1; i <= n; i++)
	{
		cin >> dp[i]; // 장당 카드 값 입력 받음
	}
	cout << DP(n);
}
