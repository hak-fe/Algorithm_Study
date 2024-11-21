#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int bsearch(vector<int>*v, int wanted);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, temp;
	vector<int>v;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		cout << bsearch(&v, temp) << '\n';
	}

	return 0;
}
int bsearch(vector<int>*v, int wanted) {
	int start = 0, end = (*v).size() - 1, mid;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if ((*v)[mid] == wanted) return 1;
		if ((*v)[mid] > wanted) end = mid - 1;
		else start = mid + 1;
	}
	return 0;
}