#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)	
		return a.first < b.first;
	else
		return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector< pair<int, int>> p;

	for (int i = 0; i < n; i++)
	{
		int first, second;
		cin >> first >> second;
		p.push_back(pair<int, int>(first, second));
	}
	sort(p.begin(), p.end(), comp);
	for (int i = 0; i < p.size(); i++)
	{
		cout << p[i].first << ' ' << p[i].second << '\n';
	}
}