#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;
int getMaxLevel(string str);
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int leftCount = 0, andHasFalse = 0, orHasTrue = 0,
		progressCount = 1, maxLevel = 0;
	string input;
	while (true)
	{
		stack<char>st;
		cin >> input;
		if (input == "()")
			break;
		leftCount = 0;
		maxLevel = getMaxLevel(input);
		for (int i = 0; i < input.length(); i++)
		{
			andHasFalse = 0, orHasTrue = 0;
			if (input[i] == '(') {
				leftCount++;
				st.push(input[i]);
			}
			else if (input[i] == 'F' || input[i] == 'T') {
				st.push(input[i]);
			}
			else {
				string temp = "";
				while (st.top() != '(') {
					temp.push_back(st.top());
					st.pop();
				}
				st.pop();
				if ((maxLevel - leftCount) % 2 == 0) {
					//AND연산
					for (int i = 0; i < temp.length(); i++)
					{
						if (temp[i] == 'F') {
							andHasFalse = 1;
							st.push('F');
							break;
						}
					}
					if (!andHasFalse)
						st.push('T');
				}
				else {
					//OR연산
					for (int i = 0; i < temp.length(); i++)
					{
						if (temp[i] == 'T') {
							orHasTrue = 1;
							st.push('T');
							break;
						}
					}
					if (!orHasTrue)
						st.push('F');
				}
				leftCount--;
			}
		}
		if (st.top() == 'T')
			cout << progressCount << ". true\n";
		else
			cout << progressCount << ". false\n";
		progressCount++;
	}
	return 0;
}
int getMaxLevel(string str) {
	int leftCnt = 0, maxLevel = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(') {
			leftCnt++;
			maxLevel = max(maxLevel, leftCnt);
		}
		else if (str[i] == ')')
			leftCnt--;
	}
	return maxLevel;
}