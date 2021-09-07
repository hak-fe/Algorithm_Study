#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
using namespace std;

int main() {

	string str;
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++)
	{
		bool isNo = false;
		vector<char>v;
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] == '(')
				v.push_back(str[j]);
			else // str[j] == ')'
			{
				if (v.empty()) {
					isNo = true;
					cout << "NO" << '\n';
					break;
				}
				else
					v.pop_back();
			}
		}
		if (!v.empty()) {
			cout << "NO" << '\n';
			isNo = true;
		}
		if (!isNo)
			cout << "YES" << '\n';
	}
}