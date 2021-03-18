#include <iostream>
#include <cstring>
using namespace std;

int main(void) {
	int time;
	int Retime;
	char str[21];

	cin >> time;
	for (int i = 0; i < time; i++)
	{
		cin >> Retime;
		cin >> str;
		for (int j = 0; j < strlen(str); j++)
		{
			for (int k = 0; k < Retime;k++)
			{
				cout << str[j];
			}
		}
		cout << '\n';
	}
}
