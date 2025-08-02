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
#define DIV 10007
#define MAX 10000
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int main() {
	vector<int>v;
	int temp;
	for (int i = 0; i < 3; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	cout << v[1];
	return 0;
}
