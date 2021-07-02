#include <iostream>
#include <string>
using namespace std;

int main() {
	int result = 0;
	char input[9][9];
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 8; j++) {
			cin >> input[i][j];
		}
	}
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 8; j++) {
			if (i % 2 == 1) { //È¦¼ö ÁÙÀÇ °æ¿ì
				if (j % 2 == 1 && input[i][j] == 'F')
					result++;
			}
			if (i % 2 == 0) { //È¦¼ö ÁÙÀÇ °æ¿ì
				if (j % 2 == 0 && input[i][j] == 'F')
					result++;
			}
		}
	}
	cout << result << '\n';
}