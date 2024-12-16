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
	
	string left, right;
	int n, cnt = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> left >> right; 
		if (left == "ChongChong") { //왼쪽이 총총
			if (map.find(right) == map.end()) {
				cnt++;
				map[right] = 0;
			}
		}
		else if (right == "ChongChong") { // 오른쪽이 총총
			if (map.find(left) == map.end()) {
				cnt++;
				map[left] = 0;
			}
		}
		else { //총총X 사람
			if (map.find(left) != map.end()) {
				if (map.find(right) == map.end()) {
					cnt++;
					map[right] = 0;
				}
			}
			else if ((map.find(right) != map.end())) {
				if (map.find(left) == map.end()) {
					cnt++;
					map[left] = 0;
				}
			}
			else
				continue;
		}
	}
	cout << cnt;
	return 0;
}