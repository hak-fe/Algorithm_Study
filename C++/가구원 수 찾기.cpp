#include <iostream>
using namespace std;

int getNum(int a, int b);

int main(void) {

	int t, k, n;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> k >> n;
		cout << getNum(k, n)<<endl;
	}

}

int getNum(int a, int b) {
	if (a == 0)
		return b;
	if (b == 1)
		return 1;
	return (getNum(a - 1, b) + getNum(a, b - 1));
}