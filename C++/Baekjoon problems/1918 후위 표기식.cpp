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
		if (str[i] >= 'A' && str[i] <= 'Z')// �ǿ������� ���
			cout << str[i]; // �״�� ���
		else
		{//�������̰ų� ��ȣ�ϰ���� ���
			if (str[i] == '(') //�°�ȣ�� ���
			{
				st.push(str[i]);
			}
			else if (str[i] == ')') //���ȣ�� ���
			{
				while (!st.empty() && st.top() != '(') // �°�ȣ�� ���� �� ���� �� ��
				{
					cout << st.top();
					st.pop();
				}
				if (!st.empty())
					st.pop();// ���������� �°�ȣ ��
			}
			else // �������� ��� 
			{
				if (!st.empty()) // ���ÿ� �̹� �����ڰ� �����ϴ� ���, �켱������ ��������
				{
					if (str[i] == '+' || str[i] == '-')
					{ // -�� +�� �켱������ ���ų� ���� �� �ۿ� ����
					 // ���ÿ� �����ϴ� �����ڸ� �� ��Ű�� ���� ǥ����� �����ڸ� Ǫ����.
						while (!st.empty() && st.top() != '(') {
							cout << st.top();
							st.pop();
						}
						st.push(str[i]);
					}
					else if ((str[i] == '*' || str[i] == '/') && (st.top() == '+' || st.top() == '-'))
					{ // �켱 ������ ���� ���
					// ���� ǥ����� �����ڸ� Ǫ��
						st.push(str[i]);
					}
					else if ((str[i] == '*' || str[i] == '/') && (st.top() == '*' || st.top() == '/'))
					{ // �켱 ������ ���� ���
						// ���ÿ� �����ϴ� �����ڸ� �� ��Ű�� ���� ǥ����� �����ڸ� Ǫ����.
						cout << st.top();
						st.pop();
						st.push(str[i]);
					}
					else//������ top�� ( �� ���
						st.push(str[i]);
				}
				else // ���ÿ� �ƹ��͵� ������ Ǫ��
					st.push(str[i]);
			}
		}
	}
	while (!st.empty()) // ���ÿ� �����ִ� �͵��� ���� ���
	{
		cout << st.top();
		st.pop();
	}
}