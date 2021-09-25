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
typedef unsigned long long int ll;

int factorial(int n) 
{
	int fac = 1;
	for (int i = 1; i <= n; i++)
	{
		fac *= i;
	}
	return fac;
}

int main()
{
	int n, k;
	cin >> n >> k;
	cout << factorial(n) / (factorial(k) * factorial(n - k)) << '\n';
}