#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

long long int ary[90] = {0, };

long long int fi(int x) {
	if (x == 1) {
		return 1;
	}
	if (x == 2) {
		return 1;
	}
	if (ary[x] != 0) {
		return ary[x];
	}
	return ary[x] = fi(x - 1) + fi(x - 2);
}

int main() {
	int n;
	cin >> n;
	cout << fi(n) << '\n';
}