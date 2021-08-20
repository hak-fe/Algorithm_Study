#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		int carPrice, option, total = 0;
		cin >> carPrice >> option;
		total += carPrice;
		for (int j = 0; j < option; j++)
		{
			int q, p;
			cin >> q >> p;
			total += q * p;
		}
		cout << total << '\n';
	}
}