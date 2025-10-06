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
int ary[31623];
int main() {
	FASTIO;
	int t;
	cin >> t;

	for (int i = 1; i <= 31622; i++)
	{
		ary[i] = i * i;
	}

	while (t--) {
		int temp;
		cin >> temp;
		cout << (ary[(int)sqrt(temp)] == temp ? 1 : 0) << endl;
	}
	return 0;
}
