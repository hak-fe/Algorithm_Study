#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	long long sum = 0;
	string a, b;
	cin >> a >> b;

	for (int i = 0; i < b.size(); i++)
	{
		for (int j = 0; j < a.size(); j++)
		{
			sum += (a[j] - '0') * (b[i] - '0');
		}
	}

	cout << sum << endl;
}