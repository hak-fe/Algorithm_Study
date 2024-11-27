#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int bsearch(vector<string>* v, string cmp);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<string>v;
	string temp;
	int n, m, cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		cnt += bsearch(&v, temp);
	}
	cout << cnt;
	return 0;
}
int bsearch(vector<string>* v, string cmp) {
	int start = 0, end = (*v).size() - 1, mid;
	while (start <= end) {
		mid = (start + end) / 2;
		if ((*v)[mid] == cmp)
			return 1;
		else if ((*v)[mid] > cmp)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return 0;
}