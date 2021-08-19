#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// �� �� 3�� �� �� 5�� �� �� 7��~
	int n, result = 0;
	cin >> n;

	int* ramen = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> ramen[i];
	}

	//1. 7���� ���
	for (int i = 0; i < n - 2; i++)
	{
		if (ramen[i] == 0)
			continue;
		/* �� ������ ������ �ݷ�
		1 1 1�� ���� �����ع�����, �ڿ� �ϳ��� ���忡�� �����ϴ� ���� 2�� �Ͼ�Ƿ� 7 + 2 * 3 = 13�� ������ �ȴ�.
		�׷���, 1 1�� ���� �����ϰ�, ���̾� 1 1 1�� �����ϸ�, 5 + 7 = 12�� �ּ� ����� ���� �� �ְ� �ȴ�.
		��, a[i + 1] > a[i + 2] �� ���� a[i + 1] - a[i + 2]��ŭ�� ���̿� a[i] �� �ּڰ��� ���� 2���� ���忡�� ��� ��츦 ���� ó�����ְ�,
		���̾� �ٷ� 3���� ���忡�� ������ �� �ִ� ��츦 ó�����ش�.
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
	// 2. 5���� ���
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
	// 3. 3���ΰ��
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