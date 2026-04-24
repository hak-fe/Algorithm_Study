#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <unordered_map>
#define MAX 1000000

using namespace std;
vector<int>parent(MAX, -1);
unordered_map <string, int> m(MAX);

int find(int a) {
	if (parent[a] == a)
		return a;
	return parent[a] = find(parent[a]);
}
void merge(vector<int>&size,int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		parent[a] = b;
		size[b] += size[a];
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int t, f;
	cin >> t;
	while (t--) {
		vector<int>size(MAX, 0);
		int cnt = 1;

		parent.assign(MAX, -1);
		m.clear();
		
		cin >> f;
		for (int i = 0; i < f; i++)
		{
			string f1, f2;
			cin >> f1 >> f2;
			if (!m.count(f1)) { // 있으면 1, 없으면 0
				m[f1] = cnt;
				parent[cnt] = cnt;
				size[cnt] = 1;
				cnt++;
			}
			if (!m.count(f2)) // 있으면 1, 없으면 0
			{
				m[f2] = cnt;
				parent[cnt] = cnt;
				size[cnt] = 1;
				cnt++;
			}
			merge(size, m[f1], m[f2]);
			cout << size[find(m[f1])] << '\n';
		}
	}

	return 0;
}