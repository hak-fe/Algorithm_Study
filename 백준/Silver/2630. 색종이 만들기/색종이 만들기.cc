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

int num[128][128];
int blue = 0, white = 0;

void rec(int n, int nx, int ny);

int main() {
	//파란색은 1, 흰색은 0
	int n, allBlue = 1, allWhite = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			cin >> num[i][j];
			if (num[i][j] == 0)
				allBlue = 0;
			else
				allWhite = 0;
		}
	}

	if (allWhite == 1 && allBlue == 0) {
		cout << 1 << endl << 0;
		return 0;
	}
	else if (allWhite == 0 && allBlue == 1) {
		cout << 0 << endl << 1;
		return 0;
	}
	else {
		rec(n / 2, 0, 0);
		rec(n / 2, 0, n / 2);
		rec(n / 2, n / 2, 0);
		rec(n / 2, n / 2, n / 2);
		cout << white << endl << blue;
	}

	return 0;
}

void rec(int n, int nx, int ny) {

	if (n == 1) {
		if (num[nx][ny] == 1) {
			blue++;
			if (DEBUG)
				cout << nx << ',' << ny << "에서 길이가 " << n << "이고 " << "전부 파란색, blue 1++" << endl;
		}
		else {
			white++;
			if (DEBUG)
				cout << nx << ',' << ny << "에서 길이가 " << n << "이고 " << "전부 흰색, white 1++" << endl;
		}
		return;
	}

	int sum = 0;
	//모두 흰색인지, 파란색인지 체크
	for (int i = nx; i < n + nx; i++)
		for (int j = ny; j < n + ny; j++)
			sum += num[i][j];

	if (sum == 0) {
		if (DEBUG)
			cout << nx << ',' << ny << "에서 길이가 " << n << "이고 " << "전부 흰색, white 1++" << endl;
		white++;
		return;
	}
	else if (sum == n * n) {
		if (DEBUG)
			cout << nx << ',' << ny << "에서 길이가 " << n << "이고 " << "전부 파란색, blue 1++" << endl;
		blue++;
		return;
	}
	else {
		rec(n / 2, nx, ny);
		rec(n / 2, nx, ny + n / 2);
		rec(n / 2, nx + n / 2, ny);
		rec(n / 2, nx + n / 2, ny + n / 2);
	}
}