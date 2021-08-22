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

	long long int n;
	cin >> n;
	long long int* ary = new long long int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> ary[i];
	}
	sort(ary, ary + n);
	cout << ary[0] * ary[n - 1];
}