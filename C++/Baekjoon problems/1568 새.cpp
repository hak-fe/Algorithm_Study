#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n, cnt = 0;
	cin >> n;
	int i = 1;
	while (true) {
		if (n == 0) {
			cout << cnt << '\n';
			break;
		}
		if (n - i < 0)
			i = 1;
		n -= i;
		cnt++;
		i++;
	}
}