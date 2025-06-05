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

vector<int>v;

void initAry(int* ary) {
	for (int i = 1; i <= 8; i++)
		ary[i] = 0;
}

void rec(int cur, int curLength, int end, int maxLength) {
	int visited[9];
	initAry(visited);
	for (int i = 1; i <= end; i++)
	{
		if (curLength <= maxLength) {
			if (i >= cur && !visited[i]) {
				visited[i] = 1;
				v.push_back(i);
				rec(i, curLength + 1, end, maxLength);
				v.pop_back();
			}
		}
		else {
			for (int i = 0; i < v.size(); i++)
				cout << v[i] << ' ';
			cout << endl;
			return;
		}
	}

}


int main() {

	int n, m;
	cin >> n >> m;
	rec(1, 1, n, m);

	return 0;
}