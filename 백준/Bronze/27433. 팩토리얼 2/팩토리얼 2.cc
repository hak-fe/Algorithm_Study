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
ll fac(int start);
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n ,sum = 0;
	cin >> n;
	sum += fac(n);
	cout << sum;
}
ll fac(int n) {
	
	if (n == 0 || n == 1)
		return 1;
	return fac(n - 1) * n;
}