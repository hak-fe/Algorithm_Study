#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long int ll;
map<string, int> mmap;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string word;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> word;
		if (word.length() >= m) {
			if (mmap.find(word) == mmap.end()) {
				mmap[word] = 1;
			}
			else
				mmap[word]++;
		}
	}
	vector<pair<string, int>> sorted(mmap.begin(), mmap.end());
	sort(sorted.begin(), sorted.end(), [](const auto& a, const auto& b) {
		// 우선순위 1: 빈도수 많은 게 우선
		if (a.second != b.second)
			return a.second > b.second;

		// 우선순위 2: 단어 길이가 긴 게 우선
		if (a.first.length() != b.first.length())
			return a.first.length() > b.first.length();

		// 우선순위 3: 알파벳 순서로 오름차순
		return a.first < b.first;
		});

	for (auto it : sorted)
		cout << it.first << '\n';

	return 0;
}