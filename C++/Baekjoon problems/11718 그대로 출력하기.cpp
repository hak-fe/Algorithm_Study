#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<string>v;
	string str;

	while (!getline(cin, str).eof()) {
			v.push_back(str);
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
}