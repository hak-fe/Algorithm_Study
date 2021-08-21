#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++)
	{
		vector<int>v;
		int jinsu;
		cin >> jinsu;
		while (true) {
			if (jinsu < 2) {
				v.push_back(jinsu);
				break;
			}
			v.push_back(jinsu % 2);
			jinsu /= 2;
		}
		/*vector<int>temp;
		for (int i = v.size() - 1; i >=0; i--)
		{
			temp.push_back(v[i]);
		}
		for (int i = 0; i < length; i++)
		{

		}*/
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] == 1)
				cout << i << ' ';
		}
	}

}