#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <deque>
using namespace std;

string EX(int a, int b, string str) {
	string result;
	//E(X) = (aX + b) mod 26
	for (int i = 0; i < str.size(); i++)
	{
		result += (a * (str[i] - 'A') + b) % 26 + 'A';
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++)
	{
		int a, b;
		string str;
		cin >> a >> b >> str;
		cout << EX(a, b, str) << '\n';
	}
}