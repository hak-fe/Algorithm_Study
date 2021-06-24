#include <iostream>
#include <cstring>
using namespace std;

int main(void) {

	char name[100];
	char LongestName[100];
	int name_len[5];
	for (int i = 0; i < 5; i++)
	{
		
		cin.getline(name, 100, ';');
		if (i == 0) {
			strcpy_s(LongestName, name);
		}
		cout << i + 1 << " : " << name << endl;
		name_len[i] = strlen(name);
		if (i > 0) {
			if (name_len[i] > name_len[i - 1]) {
				strcpy_s(LongestName, name);
			}
		}
	}
	cout << "°¡Àå ±ä ÀÌ¸§Àº " << LongestName <<endl;
}               
