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

	int n, newscore, list;
	cin >> n >> newscore >> list;
	vector<int>v;
	for (int i = 0; i < n; i++)
	{
		int score;
		cin >> score;
		v.push_back(score);
	}
	sort(v.begin(), v.end(), greater<>());

	if (n == list && v[n-1] >= newscore)
		cout << -1;
	else if (n == 0)
		cout << 1;
	else {
		int result = 1;
		for (int i = 0; i < v.size(); i++)
		{
			if (newscore < v[i])
				result++;
		}
		cout << result;
	}
}