#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <stack>
using namespace std;

char ary[100001];

int main() {

	stack<char>s;
	string str;
	getline(cin, str);
	// 문자가 들어올 때 - 스택에 넣어서 단어가 끝나면 푸쉬하여 출력
	// 태그가 들어올 때 '<' - <부터 >가 나올 때 까지 그대로 출력
	// 띄어쓰기가 들어올 때 - 공백 출력
	for (int i = 0; i < str.size();)
	{
		if (i == str.size() - 1) {
			s.push(str[i]);
			while (!s.empty()) {
				cout << s.top();
				s.pop();
			}
			return 0;
		}
		if (str[i] != ' ' && str[i] != '<') // 문자가 들어오는 경우
		{
			s.push(str[i]);
			i++;
		}
		else if (str[i] == '<') // 태그가 들어오는 경우 
		{
			while (!s.empty()) {
				cout << s.top();
				s.pop();
			}
			cout << '<';
			i++;
			while (str[i] != '>') {
				cout << str[i];
				i++;
			}
			cout << str[i];
			i++;
		}
		else if (str[i] == ' ') // 공백이 들어오는 경우
		{
			while (!s.empty()) {
				cout << s.top();
				s.pop();
			}
			i++;
			cout << ' ';
		}
	}
}