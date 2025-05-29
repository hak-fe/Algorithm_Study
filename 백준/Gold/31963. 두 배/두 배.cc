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

vector<double>seq;

double logbase(double a, double b) {
	return log(a) / log(b);
}

int main() {
	FASTIO;
	int n, res = 0;
	double temp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		seq.push_back(temp);
	}
	for (int i = 1; i < n; i++)
	{
		if (seq[i - 1] > seq[i]) {
			double x = ceil(logbase(seq[i - 1] / seq[i], 2));
			res += (int)x;
			seq[i] = seq[i] * pow(2, x);
		}
	}
	cout << res;
	return 0;
}