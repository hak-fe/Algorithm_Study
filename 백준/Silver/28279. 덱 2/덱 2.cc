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
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	deque<int>dq;
	int n, order, x;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> order;
		switch (order) {
		case 1:
			cin >> x;
			dq.push_front(x);
			break;
		case 2:
			cin >> x;
			dq.push_back(x);
			break;
		case 3:
			if (dq.empty())
				cout << -1 << '\n';
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
			break;
		case 4:
			if (dq.empty())
				cout << -1 << '\n';
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
			break;
		case 5:
			cout << dq.size() << '\n';
			break;
		case 6:
			if (dq.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
			break;
		case 7:
			if (dq.empty())
				cout << -1 << '\n';
			else
				cout << dq.front() << '\n';
			break;
		default:
			if (dq.empty())
				cout << -1 << '\n';
			else
				cout << dq.back() << '\n';
			break;
		}
	}
	return 0;
}