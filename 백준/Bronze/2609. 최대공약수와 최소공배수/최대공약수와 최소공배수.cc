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

	int a, b;
	cin >> a >> b;

	int res1 = 0, res2 = 0;

	for (int i = 1; i <= max(a, b) ; i++)
	{
		if (a % i == 0 && b % i == 0) {
			if (i > res1)
				res1 = i;
		}
	}
	int ori_a = a;
	for (int i = 1;; i++)
	{
		a = ori_a * i;
		if (a % b == 0) {
			res2 = ori_a * i;
			break;
		}
	}
	cout << res1 << '\n' << res2;
}