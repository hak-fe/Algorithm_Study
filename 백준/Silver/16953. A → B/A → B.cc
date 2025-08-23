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
int dz[2] = { 1, -1 };
int res = -1;
void min(ull a, ull b);

void func(ull n, ull m, ull depth);
int main() {
	int a, b;
	cin >> a >> b;

	func(a, b, 0);
	cout << res;
	return 0;
}

ull minUll(ull a, ull b) {
	return a < b ? a : b;
}
void func(ull a, ull b, ull depth) {
	if (a > b) {
		// cout << "a > b a: " << a << " b: " << b << endl;
		return;
	}
	else if (a == b)
	{
		// cout << "a == b a: " << a << " b: " << b << endl;
		if (res == -1)
			res = depth + 1;
		else
			res = minUll(res, depth + 1);
		return;
	}
	else {
		func(2 * a, b, depth + 1);
		func(a * 10 + 1, b, depth + 1);
	}
}