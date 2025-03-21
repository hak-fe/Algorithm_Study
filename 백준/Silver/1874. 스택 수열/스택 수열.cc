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

	int n, num = 0;
	string result;
	stack<int>st;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		while (num < temp) {
			num++;
			st.push(num);
			result.push_back('+');
		}
		if (st.top() == temp) {
			st.pop();
			result.push_back('-');
		}
		else {
			cout << "NO";
			return 0;
		}
	}

	for (int i = 0; i < result.length(); i++)
	{
		cout << result[i] << '\n';
	}

	return 0;
}