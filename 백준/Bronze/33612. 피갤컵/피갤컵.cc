#include <iostream>
using namespace std;

int main()
{
	int n, year = 2024, month = 8;
	cin >> n;
	n--;
	n *= 7;
	cout << (((month + n) % 12 == 0) ? 
		year + (month + n) / 12 - 1 : 
		year + (month + n) / 12) 
		<< ' ' <<  (((month + n) % 12 == 0) ? 12 : (month + n) % 12);
}