#include <iostream>
#include <cstring>
using namespace std;

int main(void) {

	char str[10001];
	int NumOfAllAlpha = 0;

	cout << "���� �ؽ�Ʈ�� �Է��ϼ���. ������׷��� �׸��ϴ�." << endl
		<< "�ؽ�Ʈ�� ���� ; �Դϴ�. 10000���� ���� �����մϴ�." << endl;
	cin.getline(str, 10001, ';');
/*			-���� ����-
Wise men say, only fools rush in
But I can't help, falling in love with you

Shall I stay? Would it be a sin?
If I can't help, falling in love with you

Like a river flows, surely to the sea
Darling so it goes, some things aren't meant to be ;
*/

	for (int i = 0; i < strlen(str); i++) // 1. �빮�ڸ� �ҹ��ڷ� �ٲٰ�, �� ���ĺ� ���� ���� ����
	{
		if (isalpha(str[i]) == 1 || isalpha(str[i]) == 2) {
			NumOfAllAlpha++;
		}
		if (isalpha(str[i]) == 1) {
			str[i] = tolower(str[i]);
		}
	}
	cout << "�� ���ĺ� �� " << NumOfAllAlpha << endl; //��ü ���ĺ� �� ���
	//str �迭�� ���ڿ��� �ҹ��ڷ� ���� �Ǿ� ���� ���̴�.

	for (char ch = 'a';ch <= 'z'; ch++)
	{
		int NumofAlpha = 0;
		for (int i = 0; i < strlen(str); i++)
		{
			if (str[i] == ch) {
				NumofAlpha++;
			}
		}
		cout << ch << " (" << NumofAlpha << ")   :";
		for (int j = 0; j < NumofAlpha; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

//���� : isalpha �Լ��� �ҹ��ڴ� 2, �빮�ڴ� 1, ���ĺ��� �ƴϸ� 0�� ����Ѵ�.