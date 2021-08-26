#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;

	while (getline(cin, str))
	{
		bool isfind = false;
		if (str == "EOI")
			break;
		for (int i = 0; i < str.size() - 3; i++)
		{
			if (str[i] == 'N' || str[i] == 'n')
				if (str[i + 1] == 'E' || str[i + 1] == 'e')
					if (str[i + 2] == 'M' || str[i + 2] == 'm')
						if (str[i + 3] == 'O' || str[i + 3] == 'o') {
							isfind = true;
							break;
						}
		}
		if (isfind)
			cout << "Found" << '\n';
		else
			cout << "Missing" << '\n';
	}
}