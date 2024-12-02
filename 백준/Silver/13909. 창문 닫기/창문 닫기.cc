#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long int ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, cnt = 0;

	cin >> n;
	for (int i = 1; i*i <= n; i++)
	{
		cnt++;
	}
	cout << cnt;
	return 0;
}
