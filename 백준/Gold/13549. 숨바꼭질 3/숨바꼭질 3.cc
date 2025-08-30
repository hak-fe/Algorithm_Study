#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#include <stdlib.h>

#define DEBUG 0
#define endl '\n'
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)
#define DIV 10000
#define MAX 100001
#define INF 2100000000
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int dz[2] = { 1, -1 };

vector<int>v;
int bfs(int n, int m);
int main() {
	FASTIO;

	int n, m;
	cin >> n >> m;
	v.assign(MAX, INF);
	if (n == m) {
		cout << 0;
	}
	else if (m < n) {
		cout << n - m;
	}
	else {
		//m > n의 경우
		cout << bfs(n, m);
	}

	return 0;
}

int bfs(int n, int m) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
	q.push({ 0, n });
	v[n] = 0;
	while (!q.empty()) {
		int time = q.top().first;
		int temp = q.top().second;
		q.pop();
		int left = temp - 1, right = temp + 1, twice = 2 * temp;

		if (v[temp] < time) continue;
		if (temp == m) return time;
		
		if (left >= 0 && left < MAX && v[temp] + 1 < v[left]) {
			v[left] = v[temp] + 1;
			q.push({ v[left], left});
			if (DEBUG) cout << "left : " << left << " 푸쉬, v[" << left << "] : " << v[left] << endl;
		}
		if (right >= 0 && right < MAX && v[temp] + 1 < v[right]) {
			v[right] = v[temp] + 1;
			q.push({ v[right], right});
			if (DEBUG) cout << "right : " << right << " 푸쉬, v[" << right << "] : " << v[right] << endl;
		}
		if (twice >= 0 && twice < MAX && v[temp] < v[twice]) {
			v[twice] = v[temp];
			q.push({ v[twice], twice});
			if (DEBUG) cout << "twice : " << twice << " 푸쉬, v[" << twice << "] : " << v[twice] << endl;
		}
	}
	return v[m];
}