#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{

		for (int space1 = i; space1 < n - 1; space1++)
		{
			cout << ' ';
		}
		cout << '*';
		for (int space2 = 0; space2 < 2 * i - 1; space2++)
		{
			cout << ' ';
		}
		if (n >= 3 && i > 0)
			cout << '*';
		cout << '\n';
	}
	for (int tail = 0; tail < 2 * n - 1; tail++)
	{
		cout << '*';
	}
}