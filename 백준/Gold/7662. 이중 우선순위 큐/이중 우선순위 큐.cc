#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>

#define DEBUG 1
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


int main() {
	FASTIO;
	char op;
	int t, k, input;
	cin >> t;

	while (t--) {
		priority_queue<int, vector<int>>pq_max;
		priority_queue<int, vector<int>, greater<>>pq_min;
		map<int, int> m;
		cin >> k;
		for (int i = 0; i < k; i++)
		{

			cin >> op >> input;
			if (op == 'I') {
				pq_max.push(input);
				pq_min.push(input);
				m[input]++;
			}
			else {
				if (input == 1) {
					while (!pq_max.empty()) {
						if (m[pq_max.top()] == 0)
							pq_max.pop();
						else {
							m[pq_max.top()]--;
							pq_max.pop();
							break;
						}
					}
				}
				else {
					while (!pq_min.empty()) {
						if (m[pq_min.top()] == 0)
							pq_min.pop();
						else {
							m[pq_min.top()]--;
							pq_min.pop();
							break;
						}
					}
				}
			}
		}
		while (!pq_max.empty() && m[pq_max.top()] == 0) {
			pq_max.pop();
		}
		while (!pq_min.empty() && m[pq_min.top()] == 0) {
			pq_min.pop();
		}
		if (pq_max.empty() || pq_min.empty())
			cout << "EMPTY" << endl;
		else {
			cout << pq_max.top() << ' ' << pq_min.top() << endl;
		}
	}
}