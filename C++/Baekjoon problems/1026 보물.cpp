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
	int n;
	cin >> n;
	int* ary1 = new int[n];
	int* ary2 = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> ary1[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> ary2[i];
	}
	sort(ary1, ary1 + n);
	sort(ary2, ary2 + n,greater<>());

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += ary1[i] * ary2[i];
	}
	cout << sum;
	delete[] ary1;
	delete[] ary2;
}