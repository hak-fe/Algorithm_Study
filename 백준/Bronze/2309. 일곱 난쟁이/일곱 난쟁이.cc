#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#define MAX 9
using namespace std;
int heights[10];
int check[10];
vector<int>v;
int sum = 0;
void recur(int depth);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 1; i <= MAX; i++)
	{
		cin >> heights[i];
	}
	recur(0);
	return 0;
}

void recur(int depth) {
	if (depth == 7) {
		if (sum == 100) {
			for (int i = 1; i <= MAX; i++) {
				if (check[i] == 1)
					v.push_back(heights[i]);
			}
			sort(v.begin(), v.end());
			for (int i = 0; i < v.size(); i++)
				cout << v[i] << '\n';
			exit(0);
		}
		else
			return;
	}
	else
	{
		for (int i = 1; i <= MAX; i++)
		{
			if (check[i] == 0) {
				check[i] = 1;
				sum += heights[i];
				recur(depth + 1);
				check[i] = 0;
				sum -= heights[i];
			}
		}
	}
}