#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		string str;
		getline(cin, str);
		if (str == "END")
			break;
		for (int i = str.size() - 1; i >= 0; i--)
		{
			cout << str[i];
		}
		cout << '\n';
	}
}
