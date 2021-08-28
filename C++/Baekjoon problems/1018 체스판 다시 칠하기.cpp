#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <deque>
using namespace std;

char ary[51][51];

string WB[8] = {
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW"
};
string BW[8] = {
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB"
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{	
		for (int j = 0; j < m; j++)
		{
			cin >> ary[i][j];
		}
	}

	// 1. 흰색
	int min = 0;
	for (int i = 0; i < 8 + (n - 8); i++)
	{
		for (int j = 0; j < 8 + (m - 8); j++)
		{
			int cnt = 0;
			for (int k = i; k < i + 8; k++)
			{
				for (int l = j; l < j + 8; l++)
				{
					if (ary[k][l] != WB[k - i][l - j]) {
						cnt++;
					}
				}
			}
			if (i == 0 && j == 0)
				min = cnt;
			if (cnt < min)
				min = cnt;
		}
	}
	// 2. 검은색
	for (int i = 0; i < 8 + (n - 8); i++)
	{
		for (int j = 0; j < 8 + (m - 8); j++)
		{
			int cnt = 0;
			for (int k = i; k < i + 8; k++)
			{
				for (int l = j; l < j + 8; l++)
				{
					if (ary[k][l] != BW[k - i][l - j])
						cnt++;
				}
			}
			if (cnt < min)
				min = cnt;
		}
	}
	cout << min;
}