#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int* ary = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> ary[i];
	}

	sort(ary, ary + n);

	for (int i = 0; i < n; i++)
	{
		cout << ary[i] << '\n';
	}
}