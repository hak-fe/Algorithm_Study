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

vector<ll>seq(250000, 0);
vector<int>logseq(250000, 0);

double logbase(double a, double b) {
	return log(a) / log(b);
}

int main() {
	FASTIO;
	ll n, res = 0, temp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> seq[i];
	}

	for (int i = 1; i < n; i++)
	{
		
		logseq[i] = logseq[i - 1] +
			ceil(logbase((double)seq[i - 1] / seq[i], 2));
		logseq[i] = max(logseq[i], 0);
		res += logseq[i];
	}
	cout << res;

	return 0;
}