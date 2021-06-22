#include <iostream>
using namespace std;

int main() {
	int price, cnt = 0;
	cin >> price;

	int charge = 1000 - price;


	if (charge >= 500) {
		if (charge == 0) {
			cout << cnt;
			return 0;
		}
		cnt += charge / 500;
		charge = charge - (charge / 500 * 500);
	}
	if (charge >= 100) {
		if (charge == 0) {
			cout << cnt;
			return 0;
		}
		cnt += charge / 100;
		charge = charge - (charge / 100 * 100);
	}
	if (charge >= 50) {
		if (charge == 0) {
			cout << cnt;
			return 0;
		}
		cnt += charge / 50;
		charge = charge - (charge / 50 * 50);
	}
	if (charge >= 10) {
		if (charge == 0) {
			cout << cnt;
			return 0;
		}
		cnt += charge / 10;
		charge = charge - (charge / 10 * 10);
	}
	if (charge >= 5) {
		if (charge == 0) {
			cout << cnt;
			return 0;
		}
		cnt += charge / 5;
		charge = charge - (charge / 5 * 5);
	}
	if (charge >= 1) {
		if (charge == 0) {
			cout << cnt;
			return 0;
		}
		cnt += charge / 1;
		charge = charge - (charge / 1 * 1);
	}
	cout << cnt;
}