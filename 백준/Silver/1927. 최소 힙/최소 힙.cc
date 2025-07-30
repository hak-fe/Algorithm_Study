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


int main() {
	int n, input;
	FASTIO;
	cin >> n;
	priority_queue<int, vector<int>, greater<>>pq;

	for (int i = 0; i < n; i++)
	{
		cin >> input;
		if (input == 0) {
			if (pq.size() == 0)
				cout << 0 << endl;
			else {
				cout << pq.top() << endl;
				pq.pop();
			}
		}
		else {
			pq.push(input);
		}
	}

	return 0;
}
