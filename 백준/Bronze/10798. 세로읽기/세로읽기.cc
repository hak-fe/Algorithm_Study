#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <deque>
#include <utility>

#define MIN 0
#define MAX 10000000
using namespace std;
typedef unsigned long long int ll;

string str = "@@@@@@@@@@@@@@@";

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string arr[5] = {str, str, str, str, str};
	string temp, ans;
	for (int i = 0; i < 5; i++)
	{
		cin >> temp;
		for (int j = 0; j < temp.length(); j++)
		{
			arr[i][j] = temp[j];
		}
	}

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 5; j++) {
			if (arr[j][i] != '@')
				ans += arr[j][i];
			else
				continue;
		}
	}
	cout << ans;
	
}