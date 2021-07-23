#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n % 2 == 0) {
		for (int i = 0; i < n / 2; i++)
		{
			cout << "1 2 ";
		}
	}
	else {
		for (int i = 0; i < n / 2; i++)
		{
			cout << "1 2 ";
		}
		cout << "3";
	}
}