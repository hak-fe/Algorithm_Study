#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <deque>

#define MIN 2147483647;
#define MAX 0; 

using namespace std;
typedef unsigned long long int ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; // 최대 10만개
	cin >> n;
	vector<int>v;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end(), greater<>());
	ll ans = v[0], cnt = 1;
	for (int i = 1; i < n; i++)
	{
		if (ans < v[i] * (cnt + 1))
			ans = v[i] * (cnt + 1);
		cnt++;
	}
	cout << ans << '\n';
}