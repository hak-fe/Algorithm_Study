#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>
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
vector<string>v;
int main() {
	FASTIO;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		v.push_back(str);
	}
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			if (v[i][j] >= 'A' && v[i][j] <= 'Z')
				cout << (char)(v[i][j] + 32);
			else
				cout << v[i][j];
		}
		cout << endl;
	}
	return 0;
}
