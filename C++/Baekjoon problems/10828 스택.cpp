#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	int n;
	string order;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		getline(cin, order);
		if (order.find("push") != string::npos) {
			v.push_back(stoi(order.substr(5)));
		}
		else if (order.find("pop") != string::npos) {
			if (v.size() == 0) {
				cout << -1 << endl;
			}
			else {
				cout << v.back() << endl;
				v.pop_back();
			}
		}
		else if (order.find("size") != string::npos) {
			cout << v.size() << endl;
		}
		else if (order.find("empty") != string::npos) {
			if (v.size() == 0)
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else if (order.find("top") != string::npos) {
			if (v.size() == 0) {
				cout << -1 << endl;
			}
			else {
				cout << v.back() << endl;
			}
		}
	}
}
