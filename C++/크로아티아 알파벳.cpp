#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;
// Tip - find�� replace �̿�

int main() {
	string inputStr; // �Է¹��� ���ڿ�
	vector<string> cAlpha = {"c=","c-","dz=","d-","lj","nj","s=","z="}; // ũ�ξ�Ƽ�� ���ĺ�

	cin >> inputStr;

	for (int i = 0; i < cAlpha.size(); i++)
	{
		while (true) {
			if (inputStr.find(cAlpha[i]) != string::npos)
				// find�� �� ã���� inputStr.find(cAlpha[i])�� npos�� ��ȯ
				// ���� ã����, �ش� �ε��� �� ��ȯ.
			{
				inputStr.replace(inputStr.find(cAlpha[i]), cAlpha[i].length(), "#");
			}
			else
				break;
		}
	}	
	cout << inputStr.length();
}