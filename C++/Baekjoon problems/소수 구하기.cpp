#include <iostream>
using namespace std;

int main() {

	int cnt = 0, sum = 0, min = 10000;
	int sosu1, sosu2;
	cin >> sosu1 >> sosu2;

	if (sosu1 == 1 && sosu2 == 1) {
		cout << "-1";
	}
	else {
		if (sosu1 != 1 || sosu2 != 1) {
			for (int i = sosu1; i <= sosu2; i++)
			{
				bool isSosu = true;
				if (i != 1) {
					for (int j = 2; j < i; j++)
					{
						if (i % j == 0)
							isSosu = false;
					}
					if (isSosu) {
						sum += i;
						if (i < min)
							min = i;
						cnt++;
					}
				}
			}
		}
		if (cnt == 0)
			cout << "-1";
		else
			cout << sum << endl << min;
	}
}
