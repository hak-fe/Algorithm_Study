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

void rec(int num, int cnt);
int res = 4;
int main() {
	FASTIO;
	int n;
	cin >> n;

	for (int i = max(1, (int)sqrt(n/2)), nsq = sqrt(n); i <= nsq; i++)
	{
		int tn = n;
		tn -= i * i;
		rec(tn, 1);
	}
	cout << res;
	return 0;
}
void rec(int num, int cnt) {
	
	if (num < 0 || cnt >= 4)
		return;
	if (num == 0 && cnt <= 3) {
		res = min(res, cnt);
		return;
	}
	for (int i = max(1, (int)sqrt(num/2)), nsq = sqrt(num); i <= nsq; i++)
	{
		int tn = num;
		tn -= i * i;
		rec(tn, cnt + 1);
	}
}