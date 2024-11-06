#include <iostream>
#include <stack>
#include <string>
using namespace std;

int power(int a, int b);

int main() {
	string str;
	int b, sum = 0;
	cin >> str >> b;

	for (int i = str.length() - 1; i >= 0; i--)
	{
		if (str[i] - '0' >= 0 && str[i] - '0' <= 9)
			sum += (str[i] - '0') * power(b, str.length() - 1 - i);
		else
			sum += (str[i] - 55) * power(b, str.length() - 1 - i);
	}
	cout << sum;
	return 0;
}

int power(int a, int b) {
	int sum = 1;
	for (int i = 0; i < b; i++)
		sum *= a;
	return sum;
}