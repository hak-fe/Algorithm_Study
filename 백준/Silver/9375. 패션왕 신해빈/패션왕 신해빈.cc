#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>

#define DEBUG 0
#define endl '\n'
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)
#define DIV 10007
#define MAX 2001
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	FASTIO;
	string name, kinds;
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		map<string, int>m;
		vector<string>v;
		for (int i = 0; i < n; i++)
		{
			cin >> name >> kinds;
			if (m[kinds] == 0)
				v.push_back(kinds);
			m[kinds]++;
		}
		int sum = 1;
		for (int i = 0; i < v.size(); i++)
		{
			sum *= (m[v[i]] + 1);
		}
		sum--;
		cout << sum << endl;
	}
	return 0;
}