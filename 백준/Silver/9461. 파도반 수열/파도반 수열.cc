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

using namespace std;
typedef long long int ll;

ll dp[101] = { 0, 1, 1, 1, 2, 2, };

int main() {
	
	for (int i = 6; i <= 100; i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << dp[n] << endl;
	}
	return 0;
}