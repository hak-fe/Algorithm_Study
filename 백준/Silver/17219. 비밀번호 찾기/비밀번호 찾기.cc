#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;
string wanted[100000];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unordered_map<string, string>map;
	int n, m;
	string site, password;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> site >> password;
		map.insert({site, password});
	}
	for (int i = 0; i < m; i++)
		cin >> wanted[i];
	for (int i = 0; i < m; i++)
		cout << map[wanted[i]] << '\n';
	return 0;
}