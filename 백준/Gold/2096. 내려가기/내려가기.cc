#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#include <stdlib.h>

#define DEBUG 0
#define endl '\n'
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)
#define DIV 10000
#define MAX 10001
#define INF 2100000000
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int dz[2] = { 1, -1 };

int dpMax[3];
int dpMin[3];
int input[100001][3];

void getMin(int n);
void getMax(int n);

int main() {
	FASTIO;

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> input[i][j];
		}
	}

	getMax(n);
	getMin(n);

	return 0;
}
void getMax(int n) {
	int tempDp[3] = { 0,0,0 };
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (j == 0) {
				dpMax[j] = max(tempDp[j], tempDp[j + 1]) + input[i][j];
			}
			else if (j == 1) {
				dpMax[j] = max(tempDp[j - 1], max(tempDp[j] , tempDp[j + 1])) + input[i][j];
				
			}
			else {
				dpMax[j] = max(tempDp[j - 1], tempDp[j]) + input[i][j];
			}
		}
		for (int k = 0; k < 3; k++)
		{
			tempDp[k] = dpMax[k];
		}
	}
	cout << max(dpMax[0], max(dpMax[1], dpMax[2])) << ' ';
}
void getMin(int n) {
	int tempDp[3] = { 0,0,0 };
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (j == 0) {
				dpMin[j] = min(tempDp[j], tempDp[j + 1]) + input[i][j];
			}
			else if (j == 1) {
				dpMin[j] = min(tempDp[j - 1], min(tempDp[j], tempDp[j + 1])) + input[i][j];

			}
			else {
				dpMin[j] = min(tempDp[j - 1], tempDp[j]) + input[i][j];
			}
		}
		for (int k = 0; k < 3; k++)
		{
			tempDp[k] = dpMin[k];
		}
	}
	cout << min(dpMin[0], min(dpMin[1], dpMin[2]));
}