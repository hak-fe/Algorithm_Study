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
	// ���ڰ� ���� �� - ���ÿ� �־ �ܾ ������ Ǫ���Ͽ� ���
	// �±װ� ���� �� '<' - <���� >�� ���� �� ���� �״�� ���
	// ���Ⱑ ���� �� - ���� ���
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
		if (str[i] != ' ' && str[i] != '<') // ���ڰ� ������ ���
		{
			s.push(str[i]);
			i++;
		}
		else if (str[i] == '<') // �±װ� ������ ��� 
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
		else if (str[i] == ' ') // ������ ������ ���
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