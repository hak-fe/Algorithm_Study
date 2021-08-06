#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	int maxSum = s1 + s2 + s3;

	int* cnt = new int[maxSum] {0,};
	int *temp = new int[maxSum];

	for (int i = 0; i < maxSum; i++)
	{
		temp[i] = i + 1;
	}

	for (int i = 1; i <= s1; i++)
	{
		for (int j = 1; j <= s2; j++)
		{
			for (int k = 1; k <= s3; k++)
			{
				int sum = i + j + k;
				cnt[sum - 1]++;
			}
		}
	}
	int max = cnt[0];
	for (int i = 1; i < maxSum; i++)
	{
		if (cnt[i] > max)
			max = cnt[i];
	}
	for (int i = 0; i < maxSum; i++)
	{
		if (cnt[i] == max) {
			cout << temp[i] << '\n';
			break;
		}
	}
	delete[] cnt;
}