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

	vector<int>yaksu;

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0)
			yaksu.push_back(i);
	}
	if (k > yaksu.size())
		cout << 0;
	else
		cout << yaksu[k - 1];
}