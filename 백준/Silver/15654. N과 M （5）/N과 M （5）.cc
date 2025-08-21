#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>

#define DEBUG 0
#define endl '\n'
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)
#define DIV 10000
#define MAX 10001

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int dz[2] = { 1, -1 };

vector<int>v;
vector<int>visited;
vector<int>nums;

void func(int n, int m, int depth);

int main() {
	FASTIO;
	int n, m;
	cin >> n >> m;
	v.assign(n, 0);
	visited.assign(MAX, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	func(n, m, 1);
}

void func(int n, int m, int depth) {

	for (int i = 0; i < n; i++)
	{
		if (!visited[v[i]]) {
			nums.push_back(v[i]);
			visited[v[i]] = 1;
			if (m == depth) {
				for (int i = 0; i < depth; i++)
					cout << nums[i] << ' ';
				cout << endl;
			}
			else
				func(n, m, depth + 1);
			nums.pop_back();
			visited[v[i]] = 0;
		}
	}
	return;
}