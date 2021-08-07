#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	long long n, disk;
	unsigned long long result = 0;
	cin >> n;
	unsigned long long* fileSize = new unsigned long long[n];

	for (int i = 0; i < n; i++)
	{
		cin >> fileSize[i];
	}
	cin >> disk;

	for (int i = 0; i < n; i++)
	{
		if (fileSize[i] > disk) {
			if (fileSize[i] % disk == 0)
				result += fileSize[i] / disk;
			else
				result += fileSize[i] / disk + 1;
		}
		else if (fileSize[i] == 0)
			continue;
		else
			result++;
	}
	cout << disk * result << '\n';
}