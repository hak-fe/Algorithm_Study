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

	vector<int>w;
	vector<int>k;
	for (int i = 1; i <= 20; i++)
	{
		int temp;
		cin >> temp;
		if (i <= 10)
			w.push_back(temp);
		else
			k.push_back(temp);
	}
	sort(w.begin(), w.end(), greater<>());
	sort(k.begin(), k.end(), greater<>());
	cout << w[0] + w[1] + w[2] << ' ' << k[0] + k[1] + k[2];
}