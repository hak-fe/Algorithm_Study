#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		string queue;
		getline(cin, queue);
		if (queue.find("push") != string::npos) {
			v.push_back(stoi(queue.substr(5)));
		}
		else if (queue.find("pop") != string::npos) {
			if (v.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << v.front() << endl;
				v.erase(v.begin());
			}
		}
		else if (queue.find("size") != string::npos) {
			cout << v.size() << endl;
		}
		else if (queue.find("empty") != string::npos) {
			if (v.empty())
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else if (queue.find("front") != string::npos) {
			if (v.empty()) {
				cout << -1 << endl;
			}
			else
				cout << v.front() << endl;
		}
		else if (queue.find("back") != string::npos) {
			if (v.empty()) {
				cout << -1 << endl;
			}
			else
				cout << v.back() << endl;
		}
	}
}