#include <iostream>
using namespace std;

int main() {
	int screen, basket, apple, left = 1,result = 0;

	cin >> screen >> basket >> apple;

	int* position = new int[apple];
	for (int i = 0; i < apple; i++)
	{
		cin >> position[i];
	}

	for (int i = 0; i < apple; i++)
	{
		if (position[i] < left) {
			result += left - position[i];
			left = position[i];
		}
		else if(position[i] > (left + basket - 1)) {
			result += position[i] - (left + basket - 1);
			left = position[i] - basket + 1;
		}
	}
	cout << result;
	delete position;
}