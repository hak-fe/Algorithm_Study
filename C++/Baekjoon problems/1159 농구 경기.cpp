#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	int nameAlpha[26] = { 0, };
	char alphabet[26], ch = 'a';
	cin >> n;
	
	for (int i = 0; i < 26; i++)
	{
		alphabet[i] = ch;
		ch++;
	}

	for (int i = 0; i < n; i++)
	{
		string name;
		cin >> name;
		for (int j = 'a'; j <= 'z'; j++) {
			if (name[0] == j) {
				nameAlpha[j - 97]++;
				break;
			}
		}
	}
	bool isOverFive = false;
	for (int i = 0; i < 26; i++)
	{
		if (nameAlpha[i] >= 5) {
			cout << alphabet[i];
			isOverFive = true;
		}
	}
	if (!isOverFive)
		cout << "PREDAJA" << '\n';
}