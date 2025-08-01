#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>

#define DEBUG 0
#define endl '\n'
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)
#define DIV 10007
#define MAX 2001
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int input[100001];
int sum[100001];

int main() {
	FASTIO;
	

	int n, m, x, y;

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> input[i];
	}
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + input[i];

	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		if (x == y)
			cout << input[x] << endl;
		else
			cout << sum[y] - sum[x - 1] << endl;
	}
	return 0;
}