#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <stack>
using namespace std;

int main() {
	vector<int>v;
	vector<int>result;

	int n, k, cnt = 1, index = 0;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		v.push_back(i);
	}

	while (true) {
		if (v.empty()) 
			break;
		if (cnt == k) {
			result.push_back(v[index]);
			if (index == 0) {
				v.erase(v.begin());
				index--;
			}
			else {
				v.erase(v.begin() + index);
				index--;
			}
		}
		cnt++;
		if(k != 1)
			index++;
		if (index > v.size()-1)
			index = 0;
		if (cnt > k)
			cnt = 1;
	}
	cout << "<";
	for (int i = 0; i < result.size(); i++)
	{
		if (i == result.size() - 1)
			cout << result[i];
		else
			cout << result[i] << ", ";
	}
	cout << ">";
}