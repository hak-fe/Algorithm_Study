#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	int n, t, p, totalT = 0, totalP, eachP;
	int size[6];
	cin >> n;
	for (int i = 0; i < 6; i++)
		cin >> size[i];
	cin >> t >> p;

	for (int i = 0; i < 6; i++)
	{
		if (size[i] == 0)
			continue;
		else if (size[i] % t == 0)
			totalT += size[i] / t;
		else
			totalT += size[i] / t + 1;
	}
	totalP = n / p;
	eachP = n - p * totalP;
	cout << totalT << '\n' << totalP << ' ' << eachP;
	return 0;
}