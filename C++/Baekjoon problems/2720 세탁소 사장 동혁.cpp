#include <iostream>
#include <vector>
using namespace std;


int main() {
	int n, change;
	cin >> n;
	vector<int>v;
	for (int i = 0; i < n; i++)
	{
		v.clear();
		cin >> change;
		if (change > 0) {
			if (change >= 25) {
				v.push_back(change / 25);
				change -= (change / 25) * 25;
			}
			else
				v.push_back(0);
		}
		else
			v.push_back(0);
		if (change > 0) {
			if (change >= 10) {
				v.push_back(change / 10);
				change -= (change / 10) * 10;
			}
			else
				v.push_back(0);
		}
		else
			v.push_back(0);
		if (change > 0) {
			if (change >= 5) {
				v.push_back(change / 5);
				change -= (change / 5) * 5;
			}
			else
				v.push_back(0);
		}
		else
			v.push_back(0);
		if (change > 0) {
			if (change >= 1) {
				v.push_back(change / 1);
				change -= (change / 1) * 1;
			}
			else
				v.push_back(0);
		}
		else
			v.push_back(0);
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << ' ';
		}
		cout << '\n';
	}
}