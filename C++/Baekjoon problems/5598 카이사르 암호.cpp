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

	string str, result;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 'A' || str[i] == 'B' || str[i] == 'C')
			result += str[i] + 23;
		else
			result += str[i] - 3;
	}
	cout << result;
}