#include <iostream>
#include <cstring>
using  namespace std;

int main(void) {

	int amount[26] = { 0 };
	int max = 0, cnt = 0, index = 0;

	string inputstr; //입력되는 문자열
	string ch; // inputstr에서 분리해낸 문자를 저장할 문자열
	cin >> inputstr;

	for (int i = 0; i < inputstr.size(); i++) //소문자로 바꾼다. 
	{
		if (inputstr[i] >= 65 && inputstr[i] <= 90)
			inputstr[i] += 32;
	}

	//소문자 변경 확인 완료
	//ex) mississipi

	for (int i = 0; i < inputstr.size(); i++) // inputstr문자열 한 칸 마다 아스키 코드로 적혀져 있다.
	{
		amount[inputstr[i] - 97]++;
		//해당 알파벳에 해당하는 인덱스를 ++ 시켜준다.
		//이게 곧 개수가 담긴 배열이다.
		//여기서 제일 많은 인덱스를 찾으면 됨. 동일한 인덱스가 있으면 ? 출력도 잊지말 것.
	}

	//amount 배열 입력 확인 완료

	for (int i = 0; i < 26; i++) //제일 큰 인덱스 찾는 과정;
	{
		if (amount[i] > max) {
			max = amount[i];
			index = i;
		}
	}

	for (int i = 0; i < 26; i++) //혹시 인덱스 수가 같은 건 없는지 확인하는 과정
	{
		if (max == amount[i]) {
			cnt++;
			if (cnt >= 2) { // max이외에 하나가 더 있다는 뜻
				cout << '?';
				break;
			}
		}
	}
	if (cnt <= 1)
		cout << (char)(index + 65);
}
