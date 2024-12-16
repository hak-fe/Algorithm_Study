#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;
int type[100001];
deque<int>dq;
queue<int>sequence;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, data, seq;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> type[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> data;
		if (type[i] == 0)
			dq.push_front(data);
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int temp;
		cin >> temp;
		dq.push_back(temp);
		sequence.push(temp);
	}
	if (!dq.size()) {
		for (int i = 0; i < m; i++)
		{
			cout << sequence.front() << ' ';
			sequence.pop();
		}
	}
	else {
		for (int i = 0; i < m; i++) {
			cout << dq.front() << ' ';
			dq.pop_front();
		}
	}
	return 0;
}