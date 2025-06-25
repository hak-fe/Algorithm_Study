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

ll max(ll a, ll b) {
	return a > b ? a : b;
}

vector<ll>v(100000);

int main() {
	ll n, curNum, resCnt = 0, resNum, curCnt, temp;
	
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v[i] = temp;
	}

	sort(v.begin(), v.begin() + n);
	
	resNum = v[0];
	curNum = v[0];
	curCnt = 1;

	for (int i = 1; i < n; i++)
	{
		if (v[i] == curNum)
			curCnt++;
		else {
			if (curCnt > resCnt) {
				resNum = v[i - 1];
				resCnt = curCnt;
			}
			curNum = v[i];
			curCnt = 1;
		}
	}
	if (v[n - 1] == curNum)
		if (curCnt > resCnt)
			resNum = v[n - 1];
	
	cout << resNum;
}