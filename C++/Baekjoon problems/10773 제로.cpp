#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k;
	cin >> k;
	vector<int>v;
	for (int i = 0; i < k; i++)
	{
		int n;
		cin >> n;
		if(i == 0)
			v.push_back(n);
		else {
			if (n == 0)
				v.pop_back();
			else
				v.push_back(n);
		}
	}

	int sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		sum += v[i];
	}
	cout << sum << endl;
}