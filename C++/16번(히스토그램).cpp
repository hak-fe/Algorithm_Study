#include <iostream>
#include <cstring>
using namespace std;

int main(void) {

	char str[10001];
	int NumOfAllAlpha = 0;

	cout << "영문 텍스트를 입력하세요. 히스토그램을 그립니다." << endl
		<< "텍스트의 끝은 ; 입니다. 10000글자 까지 가능합니다." << endl;
	cin.getline(str, 10001, ';');
/*			-예시 문장-
Wise men say, only fools rush in
But I can't help, falling in love with you

Shall I stay? Would it be a sin?
If I can't help, falling in love with you

Like a river flows, surely to the sea
Darling so it goes, some things aren't meant to be ;
*/

	for (int i = 0; i < strlen(str); i++) // 1. 대문자를 소문자로 바꾸고, 총 알파벳 수를 세는 과정
	{
		if (isalpha(str[i]) == 1 || isalpha(str[i]) == 2) {
			NumOfAllAlpha++;
		}
		if (isalpha(str[i]) == 1) {
			str[i] = tolower(str[i]);
		}
	}
	cout << "총 알파벳 수 " << NumOfAllAlpha << endl; //전체 알파벳 수 출력
	//str 배열의 문자열이 소문자로 정리 되어 있을 것이다.

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

//참고 : isalpha 함수는 소문자는 2, 대문자는 1, 알파벳이 아니면 0을 출력한다.