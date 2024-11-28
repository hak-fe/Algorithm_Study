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
	unordered_map<int, int>a;
	unordered_map<int, int>b;
	int numofa, numofb, tmp, ansA, ansB;
	cin >> numofa >> numofb;
	for (int i = 0; i < numofa; i++)
	{
		cin >> tmp;
		a.insert({ tmp,1 });
	}
	for (int i = 0; i < numofb; i++)
	{
		cin >> tmp;
		b.insert({ tmp,1 });
	}
	ansA = numofa;
	ansB = numofb;
	// A-B
	for (auto i : b) {
		if (a.find(i.first) != a.end()) {
			ansA--;
		}
	}
	// B-A
	for (auto i : a) {
		if (b.find(i.first) != b.end()) {
			ansB--;
		}
	}
	cout << ansA + ansB;
	return 0;
}