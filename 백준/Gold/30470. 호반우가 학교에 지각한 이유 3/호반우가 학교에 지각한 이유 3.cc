#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#include <tuple>

#define DEBUG 0
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)
#define endl '\n'
using namespace std;
typedef long long int ll;

vector<pair<ll, int>>woods;

int main() {
	FASTIO;
	ll sum = 0;
	ll n, a, b;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		if (a == 1)
			woods.push_back(make_pair(b, 1));
		else {
			if (!woods.empty()) {
				ll magic = woods.back().first - b > 0 ? woods.back().first - b : 0;
				int cnt = 0;
				for (int j = woods.size() - 1; j >= 0; j--)
				{
					if (woods[j].first >= magic) {
						cnt += woods[j].second;
						woods.pop_back();
					}
					else {
						woods.push_back(make_pair(magic, cnt));
						break;
					}
				}
				if (woods.empty() && cnt != 0)
					woods.push_back(make_pair(magic, cnt));
			}
		}
	}

	for (int i = 0; i < woods.size(); i++)
		sum += woods[i].first * woods[i].second;

	cout << sum;
	return 0;
}