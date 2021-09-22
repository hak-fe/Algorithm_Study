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
typedef unsigned long long int ll;

int dp[1001]; // 장당 카드 값을 입력받을 배열
int minnum[1001] = {}; // n개를 구매했을 때, 최솟값을 저장하는 배열

int DP(int n)
{
	minnum[0] = 0; // 0개는 0원
	for (int i = 1; i <= n; i++)
		// 1부터 n개 까지 반복한다.
	{
		minnum[i] = dp[i]; // 맨 처음에 minnum에 dp값을 넣어줌
		for (int j = 1; j <= i; j++)
		{
			minnum[i] = min(minnum[i], minnum[i - j] + minnum[j]);
			//현재 minnum값과 minnum값을 만들 수 있는 모든 경우의 값을 비교함
			// 가장 작은 minnum값을 minnum으로 재설정
		}
	}
	return minnum[n];
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