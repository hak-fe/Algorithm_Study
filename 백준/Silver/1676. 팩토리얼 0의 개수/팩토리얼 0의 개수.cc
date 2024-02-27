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

int pr(int n);
int numoftwo[501] = { 0, };
int numoffive[501] = { 0, };

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	cout << pr(n);
}
int pr(int n) {
	int ans, temp;
	for (int i = 1; i <= n; i++)
	{
		temp = i;
		numoftwo[i] += numoftwo[i - 1];
		numoffive[i] += numoffive[i - 1];
		while (temp % 2 == 0) {
			numoftwo[i]++;
			temp /= 2;
		}
		while (temp % 5 == 0) {
			numoffive[i]++;
			temp /= 5;
		}
	}
	ans = min(numoftwo[n], numoffive[n]);
	return ans;
}