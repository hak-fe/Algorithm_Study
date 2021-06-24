#include <iostream>
using namespace std;

int main() {
	int coin, money, result = 0;

	cin >> coin >> money;

	int* coinAry = new int[coin];

	for (int i = coin - 1; i >= 0; i--)
	{
		cin >> coinAry[i];
	}
	for (int i = 0; i < coin; i++)
	{
		if (money == 0)
			break;
		if (coinAry[i] <= money) {
			result += money / coinAry[i];
			money = money % coinAry[i];
		}
	}
	cout << result;
}
