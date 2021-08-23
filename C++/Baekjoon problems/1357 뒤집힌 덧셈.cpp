#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void Reverse(string a, string b) {
	string aResult, bResult;
	int res;
	for (int i = a.size() - 1; i >= 0; i--)
	{
		if (a[i] != '0')
			aResult.push_back(a[i]);
		else
			if (a[i - 1] > 0 && a[i + 1] > 0)
				aResult.push_back(a[i]);
	}
	for (int i = b.size() - 1; i >= 0; i--)
	{
		if (b[i] != '0')
			bResult.push_back(b[i]);
		else
			if (b[i - 1] > 0 && b[i + 1] > 0)
				bResult.push_back(b[i]);
	}
	res = stoi(aResult) + stoi(bResult);
	
	while (true) {
		if (res % 10 == 0)
			res /= 10;
		else
			break;
	}
	for (int i = res; i > 0; i /= 10)
	{
		cout << i % 10;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string x, y;
	cin >> x >> y;
	Reverse(x, y);
}