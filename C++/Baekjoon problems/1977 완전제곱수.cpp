#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b , min = 10001, sum = 0;
	cin >> a >> b;

	for (int i = a; i <= b; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (j * j == i) {
				if (i < min)
					min = i;
				sum += i;
				break;
			}
		}
	}

	if (!sum)
		cout << -1;
	else
	{
		cout << sum << '\n' << min;
	}
}