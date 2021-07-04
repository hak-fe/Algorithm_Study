#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n[5], result = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> n[i];
	}

	for (int i = 1;; i++)
	{
		int cnt = 0;
		for (int j = 0; j < 5; j++) {
			if (i % n[j] == 0) {
				cnt++;
			}
		}
		if (cnt >= 3) {
			result = i;
			break;
		}
	}
	cout << result << endl;
}