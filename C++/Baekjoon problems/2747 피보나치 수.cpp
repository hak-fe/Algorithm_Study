#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

long long int ary[45] = {0,};

long long int fi(int n) {
	if (n == 1)
		return 1;
	if (n == 2)
		return 1;
	if (ary[n] != 0)
		return ary[n];
	return ary[n] = fi(n - 1) + fi(n - 2);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	cout << fi(n);
}