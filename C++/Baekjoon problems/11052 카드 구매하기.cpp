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

int dp[1001]; // ��� ī�� ���� �Է¹��� �迭
int maxnum[1001] = {}; // n���� �������� ��, �ִ밪�� �����ϴ� �迭

int DP(int n) 
{
	maxnum[0] = 0; // 0���� 0��
	for (int i = 1; i <= n; i++) 
	// 1���� n�� ���� �ݺ��Ѵ�.
	{
		for (int j = 1; j <= i; j++)
		// 1���� i ���� �ݺ��Ѵ�. 1�� ��찡 1��, 2�� ��찡 2��, 3�� ��찡 3�� ... �̱� ����
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
		cin >> dp[i]; // ��� ī�� �� �Է� ����
	}
	cout << DP(n);
}
