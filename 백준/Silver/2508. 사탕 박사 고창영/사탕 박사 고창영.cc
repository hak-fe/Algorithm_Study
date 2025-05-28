#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#include <tuple>
#include <algorithm>

#define DEBUG 1
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)
#define endl '\n'
using namespace std;
typedef long long int ll;

vector<vector<char>>v;

int main() {
	FASTIO;

	int n, r, c, cnt = 0;
	cin >> n;

	while (n--) {
		cnt = 0;
		cin >> r >> c;
		v.assign(r, vector<char>(c));
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++) {
				cin >> v[i][j];
			}
		}

		//행 우선 탐색
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c - 2;) {
				if (v[i][j] == '>') {
					if (v[i][j + 1] == 'o') {
						if (v[i][j + 2] == '<') {
							cnt++;
							j += 2;
							continue;
						}
					}
				}
				j++;
			}
		}
		//열 우선 탐색
		for (int i = 0; i < c; i++)
		{
			for (int j = 0; j < r - 2;) {
				if (v[j][i] == 'v') {
					//cout << i << ", " << j << "에 v발견\n";
					if (v[j + 1][i] == 'o') {
					//	cout << i << ", " << j << "에 o발견\n";
						if (v[j + 2][i] == '^') {
						//	cout << i << ", " << j << "에 ^발견\n";
							cnt++;
							j += 2;
							continue;
						}
					}
				}
				j++;
			}
		}
		cout << cnt << endl;
	}

	return 0;
}