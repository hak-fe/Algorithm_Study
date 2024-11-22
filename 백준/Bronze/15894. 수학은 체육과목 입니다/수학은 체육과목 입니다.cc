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
	long long int n;
	cin >> n;
	cout << 2 * n + 2 * (n - 1) + 2;
	return 0;
}