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

		if (sentence == "#") // #이 나오면 프로그램 종료
			break;

		for (int i = 0; i < sentence.size(); i++) // 소문자로 바꾸고, 소문자 갯수 세는 과정
		{
			if (sentence[i] >= 65 && sentence[i] <= 90) { // 대문자일 경우
				temp.push_back(sentence[i] + 32); 
			}
			else
				temp.push_back(sentence[i]);
			if (temp[i] == 'a' || temp[i] == 'e' || temp[i] == 'i' || temp[i] == 'o' || temp[i] == 'u') {
				cnt++; // 모음 갯수 카운트 증가
			} 
		}
		cout << cnt << '\n';
	}
}