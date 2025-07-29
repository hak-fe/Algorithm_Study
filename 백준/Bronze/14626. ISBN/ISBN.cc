#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>

#define DEBUG 1
#define endl '\n'
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)
#define DIV 10007
#define MAX 2001
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	ll index, sum = 0, checkNum;
	ll num = 0;
	string str;
	cin >> str;

	checkNum = str[str.length() - 1] - '0';

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '*') {
			str[i] = '0';
			index = i;
		}
	}

	for (int i = 0; i < 12; i++)
	{
		if (i % 2 == 0) {
			sum += (str[i] - '0');
		}
		else {
			sum += 3 * (str[i] - '0');
		}
	}

	if (index % 2 == 0) {
		// * 자리는 1을 곱한 수다.
		if (!checkNum) {
			for (ll i = 0; i < 10; i++)
			{
				if ((sum + i) % 10 == 0)
				{
					cout << i; break;
				}
			}
		}
		else {
			for (ll i = 0; i < 10; i++)
			{
				if (checkNum == 10 - (sum + i) % 10) {
					cout << i;
					break;
				}
			}
		}
	}
	else {
		// * 자리는 3을 곱한 수다.
		if (!checkNum) {
			for (ll i = 0; i < 10; i++)
			{
				if ((sum + 3 * i) % 10 == 0)
				{
					cout << i; break;
				}
			}
		}
		else {
			for (ll i = 0; i < 10; i++)
			{
				if (checkNum == 10 - (sum + 3 * i) % 10) {
					cout << i;
					break;
				}
			}
		}
	}

	return 0;
}