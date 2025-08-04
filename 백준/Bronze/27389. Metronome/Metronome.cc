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


int main() {
	FASTIO;
	int n;
	cin >> n;
	if (n % 4 == 0) {
		cout << fixed;
		cout.precision(1);
		cout << (double)n / 4;
	}
	else {
		cout << fixed;
		cout.precision(2);
		cout << (double)n / 4;
	}
	return 0;
}