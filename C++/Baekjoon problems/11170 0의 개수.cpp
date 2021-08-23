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

	int testcase;
	cin >> testcase;
	cin.ignore();
	for (int i = 0; i < testcase; i++)
	{
		int cnt = 0;
		int a, b;
		cin >> a >> b;
		for (int j = a; j <= b; j++)
		{
			if (j == 0) {
				cnt++;
			}
			else {
				for (int k = j; k > 0; k /= 10)
				{
					if (k % 10 == 0)
						cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
}