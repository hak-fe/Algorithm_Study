#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>

#define DEBUG 0
#define endl '\n'
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)
#define DIV 10007
#define MAX 2001
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

ll rec(int n, ll firstRow, ll firstCol, ll inputRow, ll inputCol, ll total);

int main() {
	int n, r, c;
	cin >> n >> r >> c;
	if (n == 1) {
		if (r == 1 && c == 1)
			cout << 3;
		else if (r == 1 && c == 0)
			cout << 2;
		else if (r == 0 && c == 1)
			cout << 1;
		else
			cout << 0;
	}
	else
		cout << rec(n, 0, 0, r, c, 0);
	return 0;
}
ll rec(int n, ll firstRow, ll firstCol, ll inputRow, ll inputCol, ll total) {

	if (n == 0)
		return total;

	ll upperRow = firstRow, lowerRow = pow(2, n - 1) + firstRow,
		leftCol = firstCol, rightCol = pow(2, n - 1) + firstCol;

	//행 비교
	if (inputRow < lowerRow) {
		//1번 구역 또는 2번 구역
		if (inputCol < rightCol) {
			// 1번 구역
			if (DEBUG)
				cout << "1번 구역 시작 좌표는 " << firstRow << ", " << firstCol << " 시작 값 : " << total << endl;
			return rec(n - 1, firstRow, firstCol, inputRow, inputCol, total);
		}
		else {
			// 2번 구역
			if (DEBUG)
				cout << "2번 구역 시작 좌표는 " << firstRow << ", " << rightCol + 2 * n - 1 << " 시작 값 : " << total + pow(2, 2 * n - 2) << endl;
			return rec(n - 1, firstRow, rightCol, inputRow, inputCol, total + pow(2, 2 * n - 2));
		}
	}
	else {
		//3번 구역 또는 4번 구역
		if (inputCol < rightCol) {
			// 3번 구역
			if (DEBUG)
				cout << "3번 구역 시작 좌표는 " << lowerRow << ", " << firstCol << " 시작 값 : " << pow(2, 2 * n - 2) * 3 << endl;
			return rec(n - 1, lowerRow, firstCol, inputRow, inputCol, total + pow(2, 2 * n - 2) * 2);

		}
		else {
			// 4번 구역
			if (DEBUG)
				cout << "4번 구역 시작 좌표는 " << lowerRow << ", " << rightCol << " 시작 값 : " << pow(2, 2 * n - 2) * 3 << endl;
			return rec(n - 1, lowerRow, rightCol, inputRow, inputCol, total + pow(2, 2 * n - 2) * 3);
		}
	}
}