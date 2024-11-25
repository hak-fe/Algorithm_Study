#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a1, a0, c, n0, temp;
	cin >> a1 >> a0 >> c >> n0;
	for (int i = n0; i <= 100; i++)
	{
		temp = a1 * i + a0;
		if (temp > c * i) {
			cout << 0;
			return 0;
		}

	}
	cout << 1;
	return 0;
}