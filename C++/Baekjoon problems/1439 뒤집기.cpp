#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	int one = 0, zero = 0;
	string str;
	cin >> str;
	//00110011
	for (int i = 0; i < str.size() - 1; i++)
	{
		if (str[i] != str[i + 1]) {
			if (str[i] == '0')
				zero++;
			else
				one++;
		}
	}


	if (str[str.size() - 1] == '0') {
		zero++;
	}
	else
		one++;


		cout << min(zero, one) << endl;
}