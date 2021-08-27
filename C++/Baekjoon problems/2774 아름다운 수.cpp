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

	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++)
	{
		int num[10] = {0, };
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			num[str[j] - '0']++;
		}
		int cnt = 0;
		for (int k = 0; k < 10; k++)
		{
			if (num[k] > 0)
				cnt++;
		}
		cout << cnt << '\n';
	}

}