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

	int n, result = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int multitap;
		cin >> multitap;
		if (i == n)
			result += multitap;
		else
			result += multitap - 1;
	}
	cout << result;
}