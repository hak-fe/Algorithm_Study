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

int main() {
	int result = 0, leftCnt = 0;
	string str;
	cin >> str;

	// 쇠먁대기냐? 레이져냐? 를 판단해야함.
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(') 
		{
			leftCnt++;
		}
		else
			// 나머지는 다 우괄호
		{
			if (str[i - 1] == ')')
			{
				leftCnt--;
				result++;
			}
			else {
				leftCnt--;
				result += leftCnt;
			}
		}
	}
	cout << result;
}