#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>

#define DEBUG 0
#define endl '\n'
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)
#define DIV 10000
#define MAX 10001

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int dz[2] = { 1, -1 };

map<ll, ll>m;
map<ll, ll>visited;

void func(ll a, ll b, ll c);

int main() {
	FASTIO;
	ll a, b, c;
	cin >> a >> b >> c;

	m[1] = a % c;
	visited[1] = 1;

	func(a, b, c);

	cout << m[b] % c;
}

void func(ll a, ll b, ll c) {
	if (b <= 1)
		return;
	if (visited[b] == 1)
		return;
	visited[b] = 1;
	if (b % 2 == 1) {
		func(a, b / 2, c);
		m[b] = m[1] * m[b / 2] % c * m[b / 2] % c;
	}
	else {
		func(a, b / 2, c);
		m[b] = m[b / 2] * m[b / 2] % c;
	}
}