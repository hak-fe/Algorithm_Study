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
vector<int>v;
int fruits[10];

int checkZero();

int main() {
	FASTIO;

	int n, front = 0, back = 0, maxLen = 0;
	
	cin >> n;

	v.assign(n, 0);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	for (int i = 0; i < n; i++)
	{
		if (checkZero()) { // 과일 종류가 2개 이하
			fruits[v[i]]++;
			back++;
		}
		while (!checkZero()) {
			fruits[v[front]]--;
			front++;
		}
		maxLen = max(maxLen, back - front);
	}
	
	cout << maxLen;
	return 0;
}
int checkZero() {
	int zeroCnt = 0;
	for (int i = 1; i < 10; i++)
	{
		if (fruits[i] == 0)
			zeroCnt++;
	}
	if (zeroCnt >= 7)
		return 1;
	else
		return 0;
}