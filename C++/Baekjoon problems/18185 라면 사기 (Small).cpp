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
		/* 이 문제의 유일한 반례
		1 1 1을 먼저 구매해버리면, 뒤에 하나의 공장에서 구매하는 것이 2번 일어나므로 7 + 2 * 3 = 13이 나오게 된다.
		그러나, 1 1을 먼저 구매하고, 뒤이어 1 1 1을 구매하면, 5 + 7 = 12로 최소 비용을 구할 수 있게 된다.
		즉, a[i + 1] > a[i + 2] 일 때는 a[i + 1] - a[i + 2]만큼의 차이와 a[i] 중 최솟값을 통해 2개의 공장에서 사는 경우를 먼저 처리해주고,
		곧이어 바로 3개의 공장에서 구매할 수 있는 경우를 처리해준다.
		*/
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