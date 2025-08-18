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
		multiset<int>ms;
		/*priority_queue<int, vector<int>>pq_max;
		priority_queue<int, vector<int>, greater<>>pq_min;*/
		cin >> k;
		for (int i = 0; i < k; i++)
		{
			
			cin >> op >> input;
			if (op == 'I') {
				ms.insert(input);
			}
			else {
				if (!ms.empty()) {
					if (input == 1) {
						ms.erase(prev(ms.end()));
					}
					else {
						ms.erase(ms.begin());
					}
				}
			}
		}
		if (ms.empty())
			cout << "EMPTY" << endl;
		else 
			cout << *ms.rbegin() << ' ' << *ms.begin()<< endl;
		
	}
}