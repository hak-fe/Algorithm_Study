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
int main()
{
	string str;
	while (getline(cin, str))
	{
		bool isBalanced = true;
		stack<char>st;
		if (str == ".")
			break;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '(' || str[i] == '[')
				st.push(str[i]);
			else if (str[i] == ')') {
				if (st.empty())
					isBalanced = false;
				else
				{
					if (st.top() == '(')
						st.pop();
					else if (st.top() == '[')
						isBalanced = false;
				}
			}
			else if (str[i] == ']') {
				if (st.empty())
					isBalanced = false;
				else
				{
					if (st.top() == '[')
						st.pop();
					else if (st.top() == '(')
						isBalanced = false;
				}
			}
		}
		if (!st.empty())
			isBalanced = false;
		if (!isBalanced)
		{
			cout << "no" << '\n';
		}
		else {
			cout << "yes" << '\n';
		}
	}
}