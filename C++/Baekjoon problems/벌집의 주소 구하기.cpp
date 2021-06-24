#include <iostream>
using namespace std;

int main(void) {

	int N = 0;
	int i = 2;
	int j = 7;
	int cnt = 1;

	cin >> N;

	for (int k = 1; k <= N; k++) {
		if (N == 1) {
			break;
		}
		if (N >= i && N <= j) {
			cnt++;
			break;
		}
		else if (!(N >= i && N <= j)) {
			i += (k * 6);
			j += ((k + 1) * 6);
			cnt++;
		}
	}
	cout << cnt;
}
