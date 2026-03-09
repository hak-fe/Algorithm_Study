#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 10000
#define DIV 1000000007
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL)
#define endl '\n'

typedef unsigned long long ull;
typedef long long ll;
vector<vector<int>>grid;
int isAllZero(int startR, int startC, int r, int c) {
	for (int i = startR; i <= r; i++)
	{
		for (int j = startC; j <= c; j++)
		{
			if (grid[i][j])
				return 0;
		}
	}
	return 1;
}
int isAllOne(int startR, int startC, int r, int c) {
	for (int i = startR; i <= r; i++)
	{
		for (int j = startC; j <= c; j++)
		{
			if (!grid[i][j])
				return 0;
		}
	}
	return 1;
}
void solve(int startR, int startC, int r, int c) {
	// 함수 총 4개, 
	// 각 함수가 돌 때 마다 전부 0인지 1인지 체크하는 과정 필요.
	// 전부 0이거나 1이면 해당 숫자 출력하고 리턴
	if (isAllZero(startR, startC, r, c)) {
		//cout << startR << ", " << startC << "에서 " << r << ", " << c << "는 전부 0\n";
		cout << '0';
		return;
	}
	else if (isAllOne(startR, startC, r, c)) {
		//cout << startR << ", " << startC << "에서 " << r << ", " << c << "는 전부 1\n";
		cout << '1';
		return;
	}
	else {
		cout << '(';
		int midR = (startR + r) / 2, midC = (startC + c) / 2;
		solve(startR, startC, midR, midC);
		solve(startR, midC + 1, midR, c);
		solve(midR + 1, startC, r, midC);
		solve(midR + 1, midC + 1, r, c);
		cout << ')';
	}
	return;
}

int main() {
	FASTIO;
	char ch;
	int n;
	cin >> n;
	grid.assign(n + 1, vector<int>(n + 1));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> ch;
			grid[i][j] = ch - '0';
		}
	}

	if (isAllZero(1, 1, n, n)) {
		cout << '0';
		return 0;
	}
	if (isAllOne(1, 1, n, n)) {
		cout << '1';
		return 0;
	}
	cout << '(';
	solve(1, 1, n / 2, n / 2);
	solve(1, n / 2 + 1, n / 2, n);
	solve(n / 2 + 1, 1, n, n / 2);
	solve(n / 2 + 1, n / 2 + 1, n, n);
	cout << ')';
	return 0;
}