#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	//  �ô� 01���� 12, ���� 00���� 59, �ʴ� 00���� 59�� ��Ÿ����
	int cnt = 0;
	string clock;
	string time[3];
	cin >> clock;
	time[0] = clock.substr(0, 2);
	time[1] = clock.substr(3, 2);
	time[2] = clock.substr(6, 2);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (i != j && j != k && k != i) {
					if (stoi(time[i]) >= 1 && stoi(time[i]) <= 12 &&
						stoi(time[j]) >= 0 && stoi(time[j]) <= 59 &&
						stoi(time[k]) >= 0 && stoi(time[k]) <= 59)
						cnt++;
				}
			}
		}
	}
	cout << cnt << '\n';
}