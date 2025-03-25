#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, result = 0, skeepCount = 0;
	string str;
	vector<int>v;

	cin >> n >> str;

	if (n < 5) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == 's')
			v.push_back(1);
		else if (str[i] == 'k') {
			if (!v.empty() && v.back() == 1)
				v.back()++;
			else
				v.clear();
		}
		else if (str[i] == 'e') {
			if (!v.empty() && (v.back() == 2 || v.back() == 3))
				v.back()++;
			else
				v.clear();
		}
		else if (str[i] == 'p') {
			if (!v.empty() && v.back() == 4)
				v.back()++;
			else
				v.clear();
		}
		else
			v.clear();
		while (!v.empty() && v.back() == 5) {
			result++;
			v.pop_back();
			if (!v.empty())
				v.back()++;
		}
	}
	cout << result;
	return 0;
}