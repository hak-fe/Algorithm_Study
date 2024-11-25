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

	int a, b, c, maxNum;
	cin >> a >> b >> c;
	maxNum = max(max(a, b), c);
	if (a + b + c - maxNum <= maxNum)
		cout << (a + b + c - maxNum) + (a + b + c - maxNum) - 1;
	else
		cout << a + b + c;
	return 0;
}