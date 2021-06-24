#include <iostream>
using namespace std;

int main(void) {

	int V, A, B, i = 0;
	int day = 0;
	cin >> A >> B >> V;

	if (A == V) // A와 V가 같으면 1일차에 바로 올라감
		cout << ++day;
	else {
		if ((V - A) % (A - B) == 0) {
			day = (V - B) / (A - B);
			cout << day;
		}
		else {
			day = (V - B) / (A - B) + 1;
			cout << day;
		}
	}
}
