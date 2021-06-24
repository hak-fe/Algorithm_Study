#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main() {

	string words, changedNum;
	cin >> words;
	changedNum = words;
	int len = words.length();
	int* arr = new int[len];
	for (int i = 0; i < len; i++)
	{
		if (words[i] >= 65 && words[i] <= 67)
			changedNum[i] = '2';
		else if (words[i] >= 68 && words[i] <= 70)
			changedNum[i] = '3';
		else if (words[i] >= 71 && words[i] <= 73)
			changedNum[i] = '4';
		else if (words[i] >= 74 && words[i] <= 76)
			changedNum[i] = '5';
		else if (words[i] >= 77 && words[i] <= 79)
			changedNum[i] = '6';
		else if (words[i] >= 80 && words[i] <= 83)
			changedNum[i] = '7';
		else if (words[i] >= 84 && words[i] <= 86)
			changedNum[i] = '8';
		else if (words[i] >= 87 && words[i] <= 90)
			changedNum[i] = '9';
		else
			changedNum[i] = 0;
	}
	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		arr[i] = changedNum[i]-'0';
		sum += arr[i] + 1;
	}
	cout << sum;
}
