#include <iostream>
using namespace std;

int main() {
	int N, F, min = 200000000;

	cin >> N >> F;

	int start = (N / 100) * 100;
	int end = start + 99;

	for (int i = start; i <= end; i++)
	{
		if (i % F == 0 && i / F < min)
			min = i % 100;
	}
	int digit = 0;
	for (int i = min; i != 0; i/=10)
	{
		digit++;
	}
	if (digit == 1 || digit == 0)
		cout << '0' << min << '\n';
	else
		cout << min << '\n';
}