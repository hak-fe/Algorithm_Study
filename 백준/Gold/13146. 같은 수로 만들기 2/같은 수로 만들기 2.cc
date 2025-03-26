#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;
typedef long long int ll;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int>v;
	stack<int>st;
	int n, input, maxNum;
	ll result = 0;

	cin >> n >> input;
	maxNum = input;
	v.push_back(input);

	for (int i = 1; i < n; i++)
	{
		cin >> input;
		if (input != v.back())
			v.push_back(input);
		if (input > maxNum)
			maxNum = input;
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (st.empty()) {
			if (v[i] != maxNum)
				st.push(v[i]);
		}
		else {
			if (st.top() < v[i]) {
				result += (v[i] - st.top());
				st.pop();
				st.push(v[i]);
			}
			else {
				st.push(v[i]);
			}
		}
	}

	if (!st.empty())
		result += (maxNum - st.top());

	cout << result;

	return 0;
}