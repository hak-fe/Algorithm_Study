#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 한 개 3원 두 개 5월 세 개 7원~
	int n, result = 0;
	cin >> n;

	int* ramen = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> ramen[i];
	}

	//1. 7원인 경우
	for (int i = 0; i < n - 2; i++)
	{
		if (ramen[i] == 0)
			continue;
		if (ramen[i] >= 1 && ramen[i + 1] >= 1 && ramen[i + 2] >= 1 && ramen[i + 1] > ramen[i + 2]) {
			int temp = min(ramen[i + 1] - ramen[i + 2], ramen[i]);
			result += temp * 5;
			ramen[i] = ramen[i] - temp;
			ramen[i + 1] = ramen[i + 1] - temp;
		}
		if (ramen[i] >= 1 && ramen[i + 1] >= 1 && ramen[i + 2] >= 1) {
			result += min(ramen[i], min(ramen[i + 1], ramen[i + 2])) * 7;
			int minNum7 = min(ramen[i], min(ramen[i + 1], ramen[i + 2]));
			ramen[i] = ramen[i] - minNum7;
			ramen[i + 1] = ramen[i + 1] - minNum7;
			ramen[i + 2] = ramen[i + 2] - minNum7;
		}
	}
	// 2. 5원인 경우
	for (int i = 0; i < n - 1; i++)
	{
		if (ramen[i] == 0)
			continue;
		if (ramen[i] >= 1 && ramen[i + 1] >= 1) {
			result += min(ramen[i], ramen[i + 1]) * 5;
			int minNum5 = min(ramen[i], ramen[i + 1]);
			ramen[i] = ramen[i] - minNum5;
			ramen[i + 1] = ramen[i + 1] - minNum5;
		}
	}
	// 3. 3원인경우
	for (int i = 0; i < n; i++)
	{
		if (ramen[i] == 0)
			continue;
		if (ramen[i] >= 1) {
			result += ramen[i] * 3;
		}
	}

	cout << result;
}