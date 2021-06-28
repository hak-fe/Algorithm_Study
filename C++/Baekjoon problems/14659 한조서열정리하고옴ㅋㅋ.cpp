#include <iostream>
using namespace std;

int main() {
	int n, max = 0;
	cin >> n;
	int* mountain = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> mountain[i];
	}
	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		for (int j = i + 1; j < n; j++)
		{
			if (mountain[i] < mountain[j])
				break;
			if (mountain[i] > mountain[j]) {
				cnt++;
			}
		}
		if (cnt > max) {
			max = cnt;
		}
	}
	cout << max << endl;
}