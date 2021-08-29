#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <deque>
using namespace std;

bool cmp_length(string str1, string str2) {
	if (str1.size() < str2.size())
		return true;
	else if (str1.size() == str2.size())
	{
		if (str1 < str2)
			return true;
		else 
			return false;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	string* ary = new string[n];
	for (int i = 0; i < n; i++)
	{
		cin >> ary[i];
	}
	sort(ary, ary + n, cmp_length);
	for (int i = 0; i < n - 1; i++)
	{
		if (ary[i] == ary[i + 1])
			ary[i] = 'A';
	}
	for (int i = 0; i < n; i++)
	{
		if (ary[i] != "A")
			cout << ary[i] << '\n';
	}
	delete[] ary;
}