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
	long long n;
	cin >> n;
	if (n == 1 || n == 2)
		cout << 0 << '\n' << 3;
	else
		cout << n * (n - 1) * (n - 2) / 6 << '\n' << 3;
	return 0;
}