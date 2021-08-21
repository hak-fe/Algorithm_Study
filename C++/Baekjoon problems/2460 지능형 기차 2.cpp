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
	
	int in, out;
	cin >> out >> in;
	int max = in;
	int temp = in;
	for (int i = 1; i < 10; i++)
	{
		cin >> out >> in;
		temp -= out;
		temp += in;
		if (temp > max)
			max = temp;
	}
	cout << max;
}