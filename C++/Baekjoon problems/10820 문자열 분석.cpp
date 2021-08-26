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
	
	while (getline(cin, str)) {
		int small= 0, large = 0, number = 0, space = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				small++;
			else if (str[i] >= 'A' && str[i] <= 'Z')
				large++;
			else if (str[i] >= '0' && str[i] <= '9')
				number++;
			else if (str[i] == ' ')
				space++;
		}
		cout << small << ' ' << large << ' ' << number << ' ' << space << '\n';
	}
}