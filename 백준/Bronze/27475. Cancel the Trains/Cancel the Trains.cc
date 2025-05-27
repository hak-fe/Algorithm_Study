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

int mapBottom[101], mapLeft[101];

int main() {
	FASTIO;

	int t, n, m, temp, cnt = 0; // n == trains departing from the bottom end
	// m == trains departing from the left end
	cin >> t;
	while (t--) {
		cin >> n >> m;
		while (n--) {
			cin >> temp;
			mapBottom[temp] = 1;
		}
		while (m--) {
			cin >> temp;
			mapLeft[temp] = 1;
		}
		for (int i = 1; i <= 100; i++)
		{
			if (mapBottom[i] == 1 && mapLeft[i] == 1)
				cnt++;
		}
		cout << cnt << '\n';

		for (int i = 1; i <= 100; i++) 
			mapBottom[i] = mapLeft[i] = 0;
		cnt = 0;
	}
	return 0;
}