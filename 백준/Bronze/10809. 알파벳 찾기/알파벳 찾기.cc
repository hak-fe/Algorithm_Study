#include <iostream>
#include <cstring>
using namespace std;

int main(void) {

	char str[101];

	cin >> str;

	for (char ch = 'a'; ch <= 'z'; ch++)
	{
		int isexist = 0;
		for (int i = 0; i < strlen(str); i++)
		{
			if (str[i] == ch) {
				cout << i << " ";
				isexist = 1;
				break;
			}
		}
		if (isexist == 0) {
			cout << "-1 ";
		}
	}
}