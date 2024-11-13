#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	string a, b, c, temp;
	cin >> a >> b >> c;
	cout << stoi(a) + stoi(b) - stoi(c) << '\n';
	temp = a + b;
	cout << stoi(temp) - stoi(c) << '\n';
	return 0;
}