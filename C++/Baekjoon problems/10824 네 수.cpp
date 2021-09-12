#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

int main()
{
	string num[4];
	for (int i = 0; i < 4; i++)
	{
		cin >> num[i];
	}
	num[0] += num[1];
	num[2] += num[3];
	long long int result = stoll(num[0]) + stoll(num[2]);
	cout << result;
}