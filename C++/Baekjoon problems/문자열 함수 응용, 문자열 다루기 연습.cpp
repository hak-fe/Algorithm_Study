#include <iostream>
#include <string>
using namespace std;

int main() {

	string n1, n2, tmp = "999";
	
	cin >> n1 >> n2;
	
	int len = n1.length();

	for (int i = 0; i < len; i++)
	{
		tmp[i] = n1[len - (i + 1)];
	}
	n1 = tmp;
	for (int i = 0; i < len; i++)
	{
		tmp[i] = n2[len - (i + 1)];
	}
	n2 = tmp;

	int num1 = stoi(n1), num2 = stoi(n2);

	if (num1 > num2)
		cout << num1;
	else
		cout << num2;
}
