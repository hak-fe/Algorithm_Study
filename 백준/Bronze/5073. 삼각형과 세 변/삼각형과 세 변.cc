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
	while (1) {
		cin >> a >> b >> c;
		maxNum = max(max(a, b), c);
		if (a == b && b == c && a == 0)
			break;
		if (a + b + c - maxNum <= maxNum)
			cout << "Invalid\n";
		else if (a == b && b == c && a == c)
			cout << "Equilateral\n";
		else if (a == b || b == c || a == c)
			cout << "Isosceles\n";
		else
			cout << "Scalene\n";
	}
	return 0;
}