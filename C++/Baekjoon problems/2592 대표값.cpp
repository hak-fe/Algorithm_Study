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
	
	int ary[1001] = { 0, };
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		int temp;
		cin >> temp;
		sum += temp;
		ary[temp]++;
	}
	int max = ary[10];
	for (int i = 20; i <= 1000; i+=10)
	{
		if (ary[i] > max)
			max = i;
	}
	cout << sum / 10 << '\n' << max;
}