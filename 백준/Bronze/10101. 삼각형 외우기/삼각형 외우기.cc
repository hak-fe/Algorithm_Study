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
	
	int a, b, c;
	cin >> a >> b >> c;
	if (a + b + c == 180) {
		if (a == b && b == c && c == a)
			cout << "Equilateral";
		else if (a == b || b == c || c == a)
			cout << "Isosceles";
		else
			cout << "Scalene";
	}
	else
		cout << "Error";
	return 0;
}