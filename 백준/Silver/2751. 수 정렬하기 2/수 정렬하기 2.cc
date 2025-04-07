#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include<algorithm>
#define DEBUG 1
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
typedef long long int ll;

int main() {
	FASTIO;
	int n, temp;
	cin >> n;
	vector<int>v;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
	{
		cout << v[i] << '\n';
	}
	return 0;
}