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

int main() {
	FASTIO;

	int a = 0, sum = 0;
	for (int i = 0; i < 6; i++)
	{
		cin >> a;
		sum += a;
	}
	cout << sum * 5;
	return 0;
}