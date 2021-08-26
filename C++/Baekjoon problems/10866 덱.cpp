#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	deque<int> d;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string order;
		cin >> order;
		if (order.find("push_front") != string::npos) {
			int num;
			cin >> num;
			d.push_front(num);
		}
		else if (order.find("push_back") != string::npos) {
			int num;
			cin >> num;
			d.push_back(num);
		}
		else if (order.find("pop_front") != string::npos) {
			if (d.empty())
				cout << -1 << '\n';
			else {
				cout << d.front() << '\n';
				d.pop_front();
			}
		}
		else if (order.find("pop_back") != string::npos) {
			if (d.empty())
				cout << -1 << '\n';
			else {
				cout << d.back() << '\n';
				d.pop_back();
			}
		}
		else if (order.find("size") != string::npos) {
			cout << d.size() << '\n';
		}
		else if (order.find("empty") != string::npos) {
			if (d.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (order.find("front") != string::npos) {
			if (d.empty())
				cout << -1 << '\n';
			else
				cout << d.front() << '\n';
		}
		else if (order.find("back") != string::npos) {
			if (d.empty())
				cout << -1 << '\n';
			else
				cout << d.back() << '\n';
		}
	}
}