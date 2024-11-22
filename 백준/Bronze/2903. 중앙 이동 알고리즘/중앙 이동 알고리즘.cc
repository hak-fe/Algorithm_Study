#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
int wh[16];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long int ans;
	int n;
	cin >> n;
	wh[1] = 3;
	for (int i = 2; i <= n; i++)
	{
		wh[i] = 2 * wh[i - 1] - 1;
	}
	ans = wh[n] * wh[n];
	cout << ans;
	return 0;
}