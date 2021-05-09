#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;
// Tip - find와 replace 이용

int main() {
	string inputStr; // 입력받은 문자열
	vector<string> cAlpha = {"c=","c-","dz=","d-","lj","nj","s=","z="}; // 크로아티아 알파벳

	cin >> inputStr;

	for (int i = 0; i < cAlpha.size(); i++)
	{
		while (true) {
			if (inputStr.find(cAlpha[i]) != string::npos)
				// find로 못 찾으면 inputStr.find(cAlpha[i])가 npos를 반환
				// 만약 찾으면, 해당 인덱스 값 반환.
			{
				inputStr.replace(inputStr.find(cAlpha[i]), cAlpha[i].length(), "#");
			}
			else
				break;
		}
	}	
	cout << inputStr.length();
}