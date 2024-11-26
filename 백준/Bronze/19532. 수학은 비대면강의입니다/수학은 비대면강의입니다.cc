#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, c, d, e, f, x, y;
	cin >> a >> b >> c >> d >> e >> f;
	y = (c * d - a * f) / (b * d - a * e);
	x = (c * e - b * f) / (a * e - b * d);
	cout << x << ' ' << y;
	return 0;
}