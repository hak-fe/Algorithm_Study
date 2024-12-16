#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, sum = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
		sum *= 2;
	cout << sum;
	return 0;
}