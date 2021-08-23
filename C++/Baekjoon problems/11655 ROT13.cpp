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

	string str;
	getline(cin, str);

	for (int i = 0; i < str.size(); i++)
	{
		//대문자일 때 
		//A ~ M 까지는 + 13
		if (str[i] >= 'A' && str[i] <= 'M')
			str[i] += 13;
		//N ~ Z 까지는 - 13
		else if (str[i] >= 'N' && str[i] <= 'Z')
			str[i] -= 13;
		//소문자일 때
		//a ~ m 까지는 + 13
		else if (str[i] >= 'a' && str[i] <= 'm')
			str[i] += 13;
		//n ~ z 까지는 - 13
		else if (str[i] >= 'n' && str[i] <= 'z')
			str[i] -= 13;
	}
	cout << str;
}