#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
typedef unsigned long long int ll;

int main()
{
	stack<char>st;
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')// 피연산자일 경우
			cout << str[i]; // 그대로 출력
		else
		{//연산자이거나 괄호일경우일 경우
			if (str[i] == '(') //좌괄호일 경우
			{
				st.push(str[i]);
			}
			else if (str[i] == ')') //우괄호일 경우
			{
				while (!st.empty() && st.top() != '(') // 좌괄호를 만날 때 까지 팝 후
				{
					cout << st.top();
					st.pop();
				}
				if (!st.empty())
					st.pop();// 마지막으로 좌괄호 팝
			}
			else // 연산자일 경우 
			{
				if (!st.empty()) // 스택에 이미 연산자가 존재하는 경우, 우선순위를 따져야함
				{
					if (str[i] == '+' || str[i] == '-')
					{ // -와 +는 우선순위가 같거나 낮은 것 밖에 없음
					 // 스택에 존재하는 연산자를 팝 시키고 중위 표기식의 연산자를 푸쉬함.
						while (!st.empty() && st.top() != '(') {
							cout << st.top();
							st.pop();
						}
						st.push(str[i]);
					}
					else if ((str[i] == '*' || str[i] == '/') && (st.top() == '+' || st.top() == '-'))
					{ // 우선 순위가 높은 경우
					// 중위 표기식의 연산자를 푸쉬
						st.push(str[i]);
					}
					else if ((str[i] == '*' || str[i] == '/') && (st.top() == '*' || st.top() == '/'))
					{ // 우선 순위가 같은 경우
						// 스택에 존재하는 연산자를 팝 시키고 중위 표기식의 연산자를 푸쉬함.
						cout << st.top();
						st.pop();
						st.push(str[i]);
					}
					else//스택의 top이 ( 인 경우
						st.push(str[i]);
				}
				else // 스택에 아무것도 없으면 푸쉬
					st.push(str[i]);
			}
		}
	}
	while (!st.empty()) // 스택에 남아있는 것들을 전부 출력
	{
		cout << st.top();
		st.pop();
	}
}