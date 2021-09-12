#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

int main()
{
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++)
	{
		int a, b, r = 0 , temp_a, temp_b;
		cin >> a >> b;
		temp_a = a; temp_b = b;
		// Tip - 두 수의 곱 / 최대공약수
		if (a > b) {
			while (true) {
				r = a % b;
				if (r == 0) {
					cout << temp_a * temp_b / b << '\n';
					break;
				}
				a = b; b = r;
			}
		}
		else if (b > a) {
			while (true) {
				r = b % a;
				if (r == 0) {
					cout << temp_a * temp_b / a << '\n';
					break;
				}
				b = a; a = r;
			}
		}
		else {
			cout << a << '\n';
		}
	}
}