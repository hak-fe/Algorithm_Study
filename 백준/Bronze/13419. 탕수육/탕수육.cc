#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>
#include <stdlib.h>

#define DEBUG 0
#define endl '\n'
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)
#define DIV 10000
#define MAX 100001
#define INF 2100000000
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int dz[2] = { 1, -1 };


int main() {
	FASTIO;
	int t;
	cin >> t;
	while (t--) {
		string str, temp, p1, p2;
		cin >> str;
		if (str.length() == 1) {
			cout << str[0] << endl << str[0] << endl;
			continue;
		}
		temp = str + str;
		p1.push_back(temp[0]);
		p2.push_back(temp[1]);
		for (int i = 2; i < temp.length(); i += 2)
		{
			if (p1[0] != temp[i])
				p1.push_back(temp[i]);
			else
				break;
		}
		for (int i = 3; i < temp.length(); i += 2)
		{
			if (p2[0] != temp[i])
				p2.push_back(temp[i]);
			else
				break;
		}
		cout << p1 << endl << p2 << endl;
	}

	return 0;
}