#include <iostream>
#include <cstring>
using  namespace std;

int main(void) {

	int amount[26] = { 0 };
	int max = 0, cnt = 0, index = 0;

	string inputstr; //�ԷµǴ� ���ڿ�
	string ch; // inputstr���� �и��س� ���ڸ� ������ ���ڿ�
	cin >> inputstr;

	for (int i = 0; i < inputstr.size(); i++) //�ҹ��ڷ� �ٲ۴�. 
	{
		if (inputstr[i] >= 65 && inputstr[i] <= 90)
			inputstr[i] += 32;
	}

	//�ҹ��� ���� Ȯ�� �Ϸ�
	//ex) mississipi

	for (int i = 0; i < inputstr.size(); i++) // inputstr���ڿ� �� ĭ ���� �ƽ�Ű �ڵ�� ������ �ִ�.
	{
		amount[inputstr[i] - 97]++;
		//�ش� ���ĺ��� �ش��ϴ� �ε����� ++ �����ش�.
		//�̰� �� ������ ��� �迭�̴�.
		//���⼭ ���� ���� �ε����� ã���� ��. ������ �ε����� ������ ? ��µ� ������ ��.
	}

	//amount �迭 �Է� Ȯ�� �Ϸ�

	for (int i = 0; i < 26; i++) //���� ū �ε��� ã�� ����;
	{
		if (amount[i] > max) {
			max = amount[i];
			index = i;
		}
	}

	for (int i = 0; i < 26; i++) //Ȥ�� �ε��� ���� ���� �� ������ Ȯ���ϴ� ����
	{
		if (max == amount[i]) {
			cnt++;
			if (cnt >= 2) { // max�̿ܿ� �ϳ��� �� �ִٴ� ��
				cout << '?';
				break;
			}
		}
	}
	if (cnt <= 1)
		cout << (char)(index + 65);
}