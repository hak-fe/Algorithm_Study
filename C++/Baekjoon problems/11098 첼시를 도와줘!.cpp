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
	vector<string>result;
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++)
	{
		vector<int>price;
		vector<string>name;
		int player;
		cin >> player;
		for (int j = 0; j < player; j++)
		{
			int tempPrice;
			string tempName;
			cin >> tempPrice >> tempName;
			price.push_back(tempPrice);
			name.push_back(tempName);
		}

		int maxPrice = price[0];
		for (int i = 1; i < price.size(); i++)
		{
			if (price[i] > maxPrice)
				maxPrice = price[i];
		}
		for (int i = 0; i < price.size(); i++)
		{
			if (price[i] == maxPrice)
				result.push_back(name[i]);
		}
	}
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << '\n';
	}
}