#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>

#define DEBUG 0
#define endl '\n'
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)
#define DIV 10000
#define MAX 10000

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

//int dx[4] = { -1, 0, 1, 0 };
//int dy[4] = { 0, 1, 0, -1 };
int dz[2] = { 1, -1 };

vector<vector<int>>v;

int get1st(int n, int m);
int get2nd(int n, int m);
int get3rd(int n, int m);
int get4th(int n, int m);
int get5th(int n, int m);

int main() {
	FASTIO;
	int n, m;
	cin >> n >> m;
	v.assign(n, vector<int>(m));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> v[i][j];
	int res = max(get1st(n, m), max(get2nd(n, m), max(get3rd(n, m), max(get4th(n, m), get5th(n, m)))));
	cout << res;
}

int get1st(int n, int m) {
	int maxNum = 0;

	int dx[4] = { 0,0,0,0 };
	int dy[4] = { 0,1,2,3 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sum = 0;
			for (int k = 0; k < 4; k++)
			{
				if (i + dx[k] < 0 || i + dx[k] >= n || j + dy[k] < 0 || j + dy[k] >= m) {
					sum = 0;
					break;
				}
				sum += v[i + dx[k]][j + dy[k]];
			}
			maxNum = max(sum, maxNum);
		}
	}
	
	int dx2[4] = { 0,1,2,3 };
	int dy2[4] = { 0,0,0,0 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sum = 0;
			for (int k = 0; k < 4; k++)
			{
				if (i + dx2[k] < 0 || i + dx2[k] >= n || j + dy2[k] < 0 || j + dy2[k] >= m) {
					sum = 0;
					break;
				}
				sum += v[i + dx2[k]][j + dy2[k]];
			}
			maxNum = max(sum, maxNum);
		}
	}

	return maxNum;
}
int get2nd(int n, int m) {
	int maxNum = 0;
	int dx[4] = { 0,0,1,1 };
	int dy[4] = { 0,1,0,1 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sum = 0;
			for (int k = 0; k < 4; k++)
			{
				if (i + dx[k] < 0 || i + dx[k] >= n || j + dy[k] < 0 || j + dy[k] >= m) {
					sum = 0;
					break;
				}
				sum += v[i + dx[k]][j + dy[k]];
			}
			maxNum = max(sum, maxNum);
		}
	}
	return maxNum;
}
int get3rd(int n, int m) {
	int maxNum = 0;

	int dx[4] = { 0,1,2,2 };
	int dy[4] = { 0,0,0,1 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sum = 0;
			for (int k = 0; k < 4; k++)
			{
				if (i + dx[k] < 0 || i + dx[k] >= n || j + dy[k] < 0 || j + dy[k] >= m) {
					sum = 0;
					break;
				}
				sum += v[i + dx[k]][j + dy[k]];
			}
			maxNum = max(sum, maxNum);
		}
	}

	int dx2[4] = { 0,1,2,2 };
	int dy2[4] = { 0,0,0,-1 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sum = 0;
			for (int k = 0; k < 4; k++)
			{
				if (i + dx2[k] < 0 || i + dx2[k] >= n || j + dy2[k] < 0 || j + dy2[k] >= m) {
					sum = 0;
					break;
				}
				sum += v[i + dx2[k]][j + dy2[k]];
			}
			maxNum = max(sum, maxNum);
		}
	}

	int dx3[4] = { 0,0,1,2 };
	int dy3[4] = { 0,1,1,1 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sum = 0;
			for (int k = 0; k < 4; k++)
			{
				if (i + dx3[k] < 0 || i + dx3[k] >= n || j + dy3[k] < 0 || j + dy3[k] >= m) {
					sum = 0;
					break;
				}
				sum += v[i + dx3[k]][j + dy3[k]];
			}
			maxNum = max(sum, maxNum);
		}
	}

	int dx4[4] = { 0,1,2,0 };
	int dy4[4] = { 0,0,0,1 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sum = 0;
			for (int k = 0; k < 4; k++)
			{
				if (i + dx4[k] < 0 || i + dx4[k] >= n || j + dy4[k] < 0 || j + dy4[k] >= m) {
					sum = 0;
					break;
				}
				sum += v[i + dx4[k]][j + dy4[k]];
			}
			maxNum = max(sum, maxNum);
		}
	}

	int dx5[4] = { 0,1,0,0 };
	int dy5[4] = { 0,0,1,2 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sum = 0;
			for (int k = 0; k < 4; k++)
			{
				if (i + dx5[k] < 0 || i + dx5[k] >= n || j + dy5[k] < 0 || j + dy5[k] >= m) {
					sum = 0;
					break;
				}
				sum += v[i + dx5[k]][j + dy5[k]];
			}
			maxNum = max(sum, maxNum);
		}
	}

	int dx6[4] = { 0,0,0,1 };
	int dy6[4] = { 0,1,2,2 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sum = 0;
			for (int k = 0; k < 4; k++)
			{
				if (i + dx6[k] < 0 || i + dx6[k] >= n || j + dy6[k] < 0 || j + dy6[k] >= m) {
					sum = 0;
					break;
				}
				sum += v[i + dx6[k]][j + dy6[k]];
			}
			maxNum = max(sum, maxNum);
		}
	}

	int dx7[4] = { 0,1,1,1 };
	int dy7[4] = { 0,0,1,2 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sum = 0;
			for (int k = 0; k < 4; k++)
			{
				if (i + dx7[k] < 0 || i + dx7[k] >= n || j + dy7[k] < 0 || j + dy7[k] >= m) {
					sum = 0;
					break;
				}
				sum += v[i + dx7[k]][j + dy7[k]];
			}
			maxNum = max(sum, maxNum);
		}
	}

	int dx8[4] = { 0,0,0,-1 };
	int dy8[4] = { 0,1,2,2 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sum = 0;
			for (int k = 0; k < 4; k++)
			{
				if (i + dx8[k] < 0 || i + dx8[k] >= n || j + dy8[k] < 0 || j + dy8[k] >= m) {
					sum = 0;
					break;
				}
				sum += v[i + dx8[k]][j + dy8[k]];
			}
			maxNum = max(sum, maxNum);
		}
	}

	return maxNum;
}
int get4th(int n, int m) {
	int maxNum = 0;

	int dx[4] = { 0,1,1,2 };
	int dy[4] = { 0,0,1,1 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sum = 0;
			for (int k = 0; k < 4; k++)
			{
				if (i + dx[k] < 0 || i + dx[k] >= n || j + dy[k] < 0 || j + dy[k] >= m) {
					sum = 0;
					break;
				}
				sum += v[i + dx[k]][j + dy[k]];
			}
			maxNum = max(sum, maxNum);
		}
	}

	int dx2[4] = { 0,0,-1,-1 };
	int dy2[4] = { 0,1,1,2 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sum = 0;
			for (int k = 0; k < 4; k++)
			{
				if (i + dx2[k] < 0 || i + dx2[k] >= n || j + dy2[k] < 0 || j + dy2[k] >= m) {
					sum = 0;
					break;
				}
				sum += v[i + dx2[k]][j + dy2[k]];
			}
			maxNum = max(sum, maxNum);
		}
	}


	int dx3[4] = { 0,1,1,2 };
	int dy3[4] = { 0,0,-1,-1 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sum = 0;
			for (int k = 0; k < 4; k++)
			{
				if (i + dx3[k] < 0 || i + dx3[k] >= n || j + dy3[k] < 0 || j + dy3[k] >= m) {
					sum = 0;
					break;
				}
				sum += v[i + dx3[k]][j + dy3[k]];
			}
			maxNum = max(sum, maxNum);
		}
	}

	int dx4[4] = { 0,0,1,1 };
	int dy4[4] = { 0,1,1,2 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sum = 0;
			for (int k = 0; k < 4; k++)
			{
				if (i + dx4[k] < 0 || i + dx4[k] >= n || j + dy4[k] < 0 || j + dy4[k] >= m) {
					sum = 0;
					break;
				}
				sum += v[i + dx4[k]][j + dy4[k]];
			}
			maxNum = max(sum, maxNum);
		}
	}

	return maxNum;
}
int get5th(int n, int m) {
	int maxNum = 0;

	int dx[4] = { 0,0,0,1 };
	int dy[4] = { 0,1,2,1 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sum = 0;
			for (int k = 0; k < 4; k++)
			{
				if (i + dx[k] < 0 || i + dx[k] >= n || j + dy[k] < 0 || j + dy[k] >= m) {
					sum = 0;
					break;
				}
				sum += v[i + dx[k]][j + dy[k]];
			}
			maxNum = max(sum, maxNum);
		}
	}

	int dx2[4] = { 0,0,-1,1 };
	int dy2[4] = { 0,1,1,1 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sum = 0;
			for (int k = 0; k < 4; k++)
			{
				if (i + dx2[k] < 0 || i + dx2[k] >= n || j + dy2[k] < 0 || j + dy2[k] >= m) {
					sum = 0;
					break;
				}
				sum += v[i + dx2[k]][j + dy2[k]];
			}
			maxNum = max(sum, maxNum);
		}
	}

	int dx3[4] = { 0,0,0,-1 };
	int dy3[4] = { 0,1,2,1 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sum = 0;
			for (int k = 0; k < 4; k++)
			{
				if (i + dx3[k] < 0 || i + dx3[k] >= n || j + dy3[k] < 0 || j + dy3[k] >= m) {
					sum = 0;
					break;
				}
				sum += v[i + dx3[k]][j + dy3[k]];
			}
			maxNum = max(sum, maxNum);
		}
	}

	int dx4[4] = { 0,1,2,1 };
	int dy4[4] = { 0,0,0,1 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sum = 0;
			for (int k = 0; k < 4; k++)
			{
				if (i + dx4[k] < 0 || i + dx4[k] >= n || j + dy4[k] < 0 || j + dy4[k] >= m) {
					sum = 0;
					break;
				}
				sum += v[i + dx4[k]][j + dy4[k]];
			}
			maxNum = max(sum, maxNum);
		}
	}
	
	return maxNum;
}