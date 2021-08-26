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

	vector<int>fbi;
	bool noFbi = true;
	for (int i = 0; i < 5; i++)
	{
		string name;
		cin >> name;
		if (name.find("FBI") != string::npos) {
			noFbi = false;
			fbi.push_back(i + 1);
		}
	}
	if (noFbi)
		cout << "HE GOT AWAY!";
	else {
		for (int i = 0; i < fbi.size(); i++)
		{
			cout << fbi[i] << ' ';
		}
	}
}