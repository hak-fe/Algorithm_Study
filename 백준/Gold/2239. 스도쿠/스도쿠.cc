#include<bits/stdc++.h>
using namespace std;

#define MAX 1000000
#define DIV 1000000007
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL)
#define endl '\n'

typedef unsigned long long ull;
typedef long long ll;
/*
	목표로 해야 하는 것은 81자리 수가 가장 낮은 것.
	81자리 수가 가장 낮도록 설계를 하되, 3x3으로 나뉜 각 구역에서
	이미 사용된 수는 사용할 수 없다.
		=> 각 구역에 어떤 숫자가 사용되었는가? 여부를 판단해야한다.
			=> 행 마다 가장 작은 수 부터 우선적으로 넣되,
			   현재 3x3 칸에 해당 수가 존재하는 지 확인해야 한다.
*/
int isFound = 0;
vector<vector<int>>grid(10, vector<int>(10));
vector<vector<int>>rowCnt(10, vector<int>(10, 0));
vector<vector<int>>colCnt(10, vector<int>(10, 0));
void printGrid() {
	cout << "현재 grid\n";
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++) {
			cout << grid[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
int rowCheck(int r, int target) {
	if (!rowCnt[r][target])
		return target;
	return 0;
}
int colCheck(int c, int target) {
	if (!colCnt[target][c])
		return target;
	return 0;
}
int gridCheck(int r, int c, int target) {
	for (int i = 3 * ((r - 1) / 3) + 1; i <= 3 * ((r - 1) / 3) + 3; i++)
	{ 
		for (int j = 3 * ((c - 1) / 3) + 1; j <= 3 * ((c - 1) / 3) + 3; j++)
		{
			if (grid[i][j] == target)
				return 0;
		}
	}
	return target;
}
void checking(int r, int c) {
	if (r == 10) {
		isFound = 1;
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 1; j <= 9; j++) {
				cout << grid[i][j];
			}
			cout << endl;
		}
		return;
	}
	if (grid[r][c])
		return checking(r + (c + 1) / 10, max(1, (c + 1) % 10));
	
	for (int i = 1; i <= 9; i++)
	{
		if (rowCheck(r, i) && colCheck(c, i) && gridCheck(r, c, i)) {
			rowCnt[r][i]++;
			colCnt[i][c]++;
			grid[r][c] = i;
		//	printGrid();
			checking(r + (c + 1) / 10, max(1, (c + 1) % 10));
			if (isFound)
				return;
			grid[r][c] = 0;
			rowCnt[r][i]--;
			colCnt[i][c]--;
		}
	}
	return;
}

int main() {
	FASTIO;
	char ch;
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++) {
			cin >> ch;
			grid[i][j] = ch - '0';
			if (grid[i][j]) {
				rowCnt[i][grid[i][j]]++;
				colCnt[grid[i][j]][j]++;
			}
		}
	}
	checking(1, 1);
	return 0;
}