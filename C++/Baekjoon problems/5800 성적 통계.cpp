#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int largestGap(int temp[], int size) 
{
	int gap = temp[0] - temp[1];
	for (int i = 1; i < size - 1; i++)
	{
		if (temp[i] - temp[i + 1] > gap)
			gap = temp[i] - temp[i + 1];
	}
	return gap;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++)
	{
		cout << "Class " << i + 1 << '\n';
		int students;
		cin >> students;
		int* ary = new int[students];
		for (int j = 0; j < students; j++)
		{
			cin >> ary[j];
		}
		sort(ary, ary + students, greater<>());
		cout << "Max " << ary[0] << ", Min " << ary[students - 1] << ", Largest gap " << largestGap(ary, students) << '\n';
		delete[]ary;
	}
}