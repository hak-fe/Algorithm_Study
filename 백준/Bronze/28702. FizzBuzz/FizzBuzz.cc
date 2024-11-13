#include <iostream>
#include <stack>
#include <string>
using namespace std;
/*
FizzBuzz
Fizz
Buzz
*/
int main() {
	string str[3], res;
	for (int i = 0; i < 3; i++) 
		cin >> str[i];

	for (int i = 0; i < 3; i++) {
		if (str[i] != "FizzBuzz" && str[i] != "Fizz" && str[i] != "Buzz") {
			res = to_string(stoi(str[i]) + (3 - i));
			if (stoi(res) % 3 == 0 && stoi(res) % 5 == 0)
				cout << "FizzBuzz";
			else if (stoi(res) % 3 == 0 && stoi(res) % 5 != 0)
				cout << "Fizz";
			else if (stoi(res) % 3 != 0 && stoi(res) % 5 == 0)
				cout << "Buzz";
			else
				cout << res;
			break;
		}
	}
	return 0;
}