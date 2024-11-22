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
	string str = " is NOT perfect.\n";
	vector<int> v;
	int n, sum = 1;
	while (1) {
		cin >> n;
		if (n == -1)
			return 0;
		for(int i = 2; i < n; i++)
			if (n % i == 0) {
				v.push_back(i);
				sum += i;
			}
		if (sum == n) { // 완벽수인 경우
			cout << n << " = 1";
			for (int i = 0; i < v.size(); i++)
				cout << " + " << v[i];
			cout << '\n';
		}
		else
			cout << n << str;
		sum = 1;
		v.clear();
	}
	return 0;
}