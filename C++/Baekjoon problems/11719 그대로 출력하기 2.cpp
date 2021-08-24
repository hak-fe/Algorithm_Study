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

	int point;
	cin >> point;
	int* x = new int[point];
	int* y = new int[point];
	for (int i = 0; i < point; i++)
	{
		cin >> x[i] >> y[i];
	}
	sort(x, x + point);
	sort(y, y + point);
	for (int i = 0; i < point; i++)
	{
		cout << x[i] << ' ' << y[i] << '\n';
	}
}