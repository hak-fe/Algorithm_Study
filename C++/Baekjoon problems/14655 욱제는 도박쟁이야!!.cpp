#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	int coin;
	cin >> coin;

	int* firstRound = new int[coin];
	int* secondRound = new int[coin];

	for (int i = 0; i < coin; i++)
	{
		cin >> firstRound[i];
	}
	for (int i = 0; i < coin; i++)
	{
		cin >> secondRound[i];
	}
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0; i < coin; i++)
	{
		sum1 += abs(firstRound[i]);
		if (secondRound[i] > 0) {
			secondRound[i] = -secondRound[i];
		}
		sum2 += secondRound[i];
	}
	cout << sum1 - sum2 << endl;
	delete firstRound;
	delete secondRound;
}