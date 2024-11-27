#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<string> temp;
	unordered_map<string, string> map;
	string name, condition;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> name >> condition;
		if (condition == "enter")
			map.insert({ name, condition });
		else
			map.erase(name);
	}
	for (auto i : map)
		temp.push_back(i.first);
	sort(temp.begin(), temp.end(),greater<>());
	for (auto i : temp)
		cout << i << '\n';
	return 0;
}