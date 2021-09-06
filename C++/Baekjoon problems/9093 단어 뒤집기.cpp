#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
	int testcase;
	string str;
	cin >> testcase;
	cin.ignore();
	for (int i = 0; i < testcase; i++)
	{
		vector<char>v;
		getline(cin, str);
		for (int j = 0; j < str.size(); j++)
		{
			if (j == str.size() - 1) {
				v.push_back(str[j]);
				for (; v.empty() != true;)
				{
					cout << v.back();
					v.pop_back();
				}
			}
			if (str[j] == ' ') 
			{
				for (; v.empty() != true;)
				{
					cout << v.back();
					v.pop_back();
				}
				cout << ' ';
			}
			else
				v.push_back(str[j]);
		}	
		cout << '\n';
	}
}