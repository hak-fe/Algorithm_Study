#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int room[31] = {0, };
	for (int i = 0; i < 28; i++)
	{
		int studentNum;
		cin >> studentNum;
		room[studentNum] = 1;
	}
	for (int i = 1; i <= 30; i++)
	{
		if (room[i] == 0)
			cout << i << '\n';
	}
}