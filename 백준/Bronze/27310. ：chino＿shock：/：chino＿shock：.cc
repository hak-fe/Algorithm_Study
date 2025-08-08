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
	FASTIO;
	int cnt = 0;
	string str;
	cin >> str;
	for (int i = 6; i < str.length(); i++)
	{
		if (str[i] == '_')
			cnt++;
	}
	cout << str.length() + 2 + cnt * 5;
}
