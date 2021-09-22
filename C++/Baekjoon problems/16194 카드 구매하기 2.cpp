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

int dp[1001]; // ��� ī�� ���� �Է¹��� �迭
int minnum[1001] = {}; // n���� �������� ��, �ּڰ��� �����ϴ� �迭

int DP(int n)
{
	minnum[0] = 0; // 0���� 0��
	for (int i = 1; i <= n; i++)
		// 1���� n�� ���� �ݺ��Ѵ�.
	{
		minnum[i] = dp[i]; // �� ó���� minnum�� dp���� �־���
		for (int j = 1; j <= i; j++)
		{
			minnum[i] = min(minnum[i], minnum[i - j] + minnum[j]);
			//���� minnum���� minnum���� ���� �� �ִ� ��� ����� ���� ����
			// ���� ���� minnum���� minnum���� �缳��
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
		cin >> dp[i]; // ��� ī�� �� �Է� ����
	}
	cout << DP(n);
}