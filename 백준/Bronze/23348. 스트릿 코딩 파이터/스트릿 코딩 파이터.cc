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
vector<string>v;
int main() {
	FASTIO;
	int a, b, c, n, temp, maxNum = 0;
	cin >> a >> b >> c >> n;
	while (n--) {
		temp = 0;
		for (int i = 0; i < 3; i++)
		{
			int skill;
			for (int j = 0; j < 3; j++)
			{
				cin >> skill;
				switch (j)
				{
				case 0: temp = temp + skill * a; break;
				case 1: temp = temp + skill * b; break;
				case 2: temp = temp + skill * c; break;
				}
			}
		}
		maxNum = max(maxNum, temp);
	}
	cout << maxNum;
	return 0;
}
