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

	int first, second;
	while (1) {
		cin >> first >> second;
		if (first == second && first == 0)
			return 0;
		if (second % first == 0)
			cout << "factor" << '\n';
		else if (first % second == 0)
			cout << "multiple" << '\n';
		else
			cout << "neither" << '\n';
	}
	return 0;
}