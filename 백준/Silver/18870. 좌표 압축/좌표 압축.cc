#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int bsearch(vector<int>* value, int comp);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, temp;
	vector<int>v;
	vector<int>res;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v.push_back(temp);
		res.push_back(temp);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < n; i++)
	{
		cout << bsearch(&v, res[i]) << ' ';
	}
	return 0;
}
int bsearch(vector<int>* value, int comp) {
	int start = 0, end = (*value).size() - 1, mid;
	while (start <= end) {
		mid = (start + end) / 2;
		if ((*value)[mid] == comp)
			return mid;
		else if ((*value)[mid] > comp)
			end = mid - 1;
		else
			start = mid + 1;
	}
}