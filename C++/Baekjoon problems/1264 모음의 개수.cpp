#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	while (true) {
		int cnt = 0;
		string sentence,temp;
		getline(cin, sentence);

		if (sentence == "#") // #�� ������ ���α׷� ����
			break;

		for (int i = 0; i < sentence.size(); i++) // �ҹ��ڷ� �ٲٰ�, �ҹ��� ���� ���� ����
		{
			if (sentence[i] >= 65 && sentence[i] <= 90) { // �빮���� ���
				temp.push_back(sentence[i] + 32); 
			}
			else
				temp.push_back(sentence[i]);
			if (temp[i] == 'a' || temp[i] == 'e' || temp[i] == 'i' || temp[i] == 'o' || temp[i] == 'u') {
				cnt++; // ���� ���� ī��Ʈ ����
			} 
		}
		cout << cnt << '\n';
	}
}