#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string>v;
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		string temp;
		for (int j = i; j < str.size(); j++)
		{
			temp += str[j];
		}
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << '\n';
	}
}