#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <deque>
using namespace std;

int dpa[46] = {}, dpb[46] = {};

int aDP(int n) {
	if (n == 0) return 1;
	if (n == 1) return 0;
	if (n == 2) return 1;
	if (dpa[n] != 0) return dpa[n];
	return dpa[n] = aDP(n - 1) + aDP(n - 2);
}

int bDP(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (n == 2) return 1;
	if (dpb[n] != 0) return dpb[n];
	return dpb[n] = bDP(n - 1) + bDP(n - 2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	cout << aDP(n) << ' ' << bDP(n);
}