#include <iostream>
using namespace std;

int main() {

	int soinsu;
	cin >> soinsu;
	if (soinsu == 1)
		return 0;
	int i = 2;
	while (true) {
		if (soinsu / i == 0)
			break;
		if (soinsu % i == 0) {
			cout << i << endl;
			soinsu /= i;
		}
		else
			i++;
	}
}