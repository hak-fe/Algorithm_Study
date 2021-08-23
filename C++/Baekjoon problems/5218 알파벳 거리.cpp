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

	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++)
	{
		string x, y;
		cin >> x >> y;
		cout << "Distances: ";
		for (int j = 0; j < x.size(); j++)
		{
			if (y[j] >= x[j])
				cout << (y[j] - 64) - (x[j] - 64) << ' ';
			else
				cout << (y[j] - 64 + 26) - (x[j] - 64) << ' ';

		}
		cout << '\n';
	}
}