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

	string str[3];
	for (int i = 0; i < 3; i++)
	{
		bool isAllSame = true;
		cin >> str[i];
		vector<int>v;
		int cnt = 1;
		for (int j = 0; j < str[i].size() - 1; j++)
		{
			if (str[i][j] == str[i][j + 1]) {
				cnt++;
			}
			else {
				isAllSame = false;
				v.push_back(cnt);
				cnt = 1;
			}
			if (j == 6)
				v.push_back(cnt);
		}
		if (isAllSame)
			v.push_back(cnt);
		if (v.empty())
			cout << 1 << '\n';
		else {
			int max = 0;
			for (int j = 0; j < v.size(); j++)
			{
				if (v[j] > max)
					max = v[j];
			}
			cout << max << '\n';
		}
	}

}