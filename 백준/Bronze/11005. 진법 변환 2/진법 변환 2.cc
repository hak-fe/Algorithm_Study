#include <iostream>
#include <stack>
#include <string>
using namespace std;

void exp(int sum, int b);

int main() {
	int sum, b;
	cin >> sum >> b;
	exp(sum, b);
	return 0;
}

void exp(int sum, int b) {
	if (sum > 0) {
		exp(sum / b, b);
		if (sum % b >= 0 && sum % b <= 9)
			cout << sum % b;
		else
			cout << (char)(sum % b + 55);
	}
}