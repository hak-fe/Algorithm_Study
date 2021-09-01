#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, n;
	cin >> a >> b >> n;

	if (a % b == 0) 
		cout << 0;
	else {
		vector<int>v;
		a = a % b;
		for (int i = 0; i < n; i++)
		{
			a *= 10;
			v.push_back(a / b);
			a = a % b;
		}
		cout << v[n - 1];
	}
}