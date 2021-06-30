#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int* sort = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> sort[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++) {
			if (sort[j] > sort[j + 1]) {
				int temp = sort[j];
				sort[j] = sort[j + 1];
				sort[j + 1] = temp;
			}
			
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << sort[i] << endl;
	}
}