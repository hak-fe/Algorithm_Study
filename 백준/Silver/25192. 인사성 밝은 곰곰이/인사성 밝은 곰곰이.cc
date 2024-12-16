#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;
unordered_map<string, int> map;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, cnt = 0;
	string tmp;
	cin >> n;
	cin >> tmp;
	for (int i = 1; i < n; i++)
	{
		cin >> tmp;
		if (tmp != "ENTER") {
			if (map.size() == 0 || map.find(tmp) == map.end()) {
				cnt++;
				map[tmp] = 0;
			}
			else
				continue;
		}
		else
			map.clear();
	}
	cout << cnt;
	return 0;
}