#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <deque>
#include <utility>

#define MIN 0
#define MAX 10000000

using namespace std;
typedef unsigned long long int ll;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num1, num2, num3;
	cin >> num1 >> num2 >> num3;

	if (num1 == num2 && num2 == num3) // 1. 나온 눈이 다 같은 경우
		cout << 10000 + num1 * 1000;
	else if (num1 == num2) // 2. 2개가 같은 경우
		cout << 1000 + num1 * 100;
	else if (num1 == num3)
		cout << 1000 + num1 * 100;
	else if (num2 == num3)
		cout << 1000 + num2 * 100;
	else // 3. 3개 전부 다른 경우
		cout << max(num3, max(num1, num2)) * 100;
}