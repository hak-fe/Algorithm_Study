#include <iostream>
using namespace std;

int main() {
	int peopleNum, minusTime, result = 0;
	cin >> peopleNum;

	int* time = new int[peopleNum];

	for (int i = 0; i < peopleNum; i++)
	{
		cin >> time[i];
	}

	for (int i = 0; i < peopleNum; i++)
	{
		for (int j = 0; j < peopleNum - 1 - i ; j++) {
			if (time[j] > time[j + 1]) {
				int temp = time[j];
				time[j] = time[j + 1];
				time[j + 1] = temp;
			}
		}
	}
	minusTime = peopleNum;
	for (int i = 0; i < peopleNum; i++)
	{
		result += time[i] * minusTime;
		minusTime--;
	}
	cout << result;
}