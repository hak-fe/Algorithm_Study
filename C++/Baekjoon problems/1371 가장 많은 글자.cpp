#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	int alpha[26] = { 0, };
	vector<int>indexVector;
	string sentence;
	while (getline(cin, sentence)) {
		for (int i = 0; i < sentence.size(); i++)
		{
			alpha[sentence[i] - 97]++;
		}
	}

	int max = alpha[0];

	for (int i = 1; i < 26; i++) // �ϴ� �ִ� ���� ���ϰ�
	{
		if (alpha[i] >= max) {
			max = alpha[i];
		}
	}
	for (int i = 0; i < 26; i++) //�ִ񰪰� ���� ���� �ִ��� ã�´�
	{// �� �ε����� ���Ϳ� ����
		if (alpha[i] == max) {
			indexVector.push_back(i);
		}
	}
	for (int i = 0; i < indexVector.size(); i++)
	{
		char temp = indexVector[i] + 'a';
		cout << temp;
	}
}