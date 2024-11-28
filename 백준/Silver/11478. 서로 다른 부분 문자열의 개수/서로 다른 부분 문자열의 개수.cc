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
	int cnt = 0;
	unordered_map<string, int>map;
	string str, tmp;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		for (int j = 0; j < str.length() - i; j++) 
		{
			tmp = str.substr(j, i + 1);
			if (map.find(tmp) == map.end())
			{
				map.insert({ tmp,1 });
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}