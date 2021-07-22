#include <iostream>
#include <string>
using namespace std;

int main() {
	int len,cnt = 0;
	string str;
	cin >> len >> str;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == NULL)
			break;
		if (str[i] == 'p') {
			if (str[i + 1] == NULL)
				break;
			if (str[i + 1] == 'P') {
				if (str[i + 2] == 'A') {
					if (str[i + 3] == 'p') {
						cnt++;
						i+=3;
					}
				}
			}
		}
	}
	cout << cnt;
}