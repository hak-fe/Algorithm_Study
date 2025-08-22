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

vector<int>seqs; // 수열 저장
vector<int>temp; // 출력용
vector<int>visited; // 출력용

void func(int n, int m, int depth);

int main() {
	FASTIO;
	int n, m;
	cin >> n >> m;
	seqs.assign(n, 0);
	visited.assign(MAX, 0);

	for (int i = 0; i < n; i++)
		cin >> seqs[i];

	sort(seqs.begin(), seqs.end());

	func(n, m, 1);
}

void func(int n, int m, int depth) {
	int lastNum = 0;
	for (int i = 0; i < n; i++)
	{
		if (!visited[i] && lastNum != seqs[i]) {
			temp.push_back(seqs[i]);
			visited[i] = 1;
			lastNum = seqs[i];

			if (depth == m) {
				for (int j = 0; j < depth; j++)
				{
					cout << temp[j] << ' ';
				}
				cout << endl;
			}
			else
				func(n, m, depth + 1);
			temp.pop_back();
			visited[i] = 0;
		}
	}
	return;
}