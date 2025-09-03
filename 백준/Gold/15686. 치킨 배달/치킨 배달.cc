#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#include <stdlib.h>

#define DEBUG 0
#define endl '\n'
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)
#define DIV 10000
#define MAX 100001
#define INF 2100000000
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int dz[2] = { 1, -1 };

vector<vector<int>>v;
vector<pair<int, int>> bbq;
vector<pair<int, int>> home;
vector<pair<int, int>> temp;

void bt(int start, int depth,int n, int m, int *res);
int getMinChickenLength(vector<pair<int, int>> temp, int n);
int getMinLen(pair<int, int>bbqCoord, pair<int, int>homeCoord);
int main() {
	FASTIO;

	int n, m, res = INF;
	cin >> n >> m;
	v.assign(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) {
			cin >> v[i][j];
			if (v[i][j] == 1)
				home.push_back({ i, j });
			if (v[i][j] == 2)
				bbq.push_back({ i, j });
		}
	}
	bt(0, 0, n, m, &res);
	cout << res;
	// 최대 m개의 치킨집을 선택.
	// 치킨집의 좌표를 bbq에 담아놓았음.
	// bbq에서 조합으로 m개를 선택함.
	// m개를 임의로 선택한 후, m개의 치킨집에 대한 모든 가정집의 최소 치킨거리를 구함.
	// 백트래킹으로 계속 구하면서 최종적으로 최솟값을 리턴
	// 구하는 방식은 백트래킹으로.
	
	return 0;
}

void bt(int start, int depth,int n, int m, int* res) {
	if (depth == m) {
		*res = min(*res, getMinChickenLength(temp, n));
		return;
	}
	for (int i = start; i < bbq.size() ; i++)
	{
		temp.push_back(bbq[i]);
		bt(i + 1, depth + 1, n, m, res);
		temp.pop_back();
	}
}
int getMinChickenLength(vector<pair<int, int>> temp, int n) {
	//각 치킨집에 대한 모든 가정집의 치킨거리를 계산함.
	// 그 중 최솟값을 찾아서 누적합.
	//최종적으로 치킨집 m개와 모든 가정집에 대한 치킨거리 누적합을 구하고 리턴해줌
	int res = 0, minLen = INF;
	for (int i = 0; i < home.size(); i++)
	{
		pair<int, int> coord = home[i];
		for (int j = 0; j < temp.size(); j++)
		{
			minLen = min(getMinLen(coord, temp[j]), minLen);
		}
		res += minLen;
		minLen = INF;
	}
	return res;
}
int getMinLen(pair<int, int>bbqCoord, pair<int, int>homeCoord) {
	return abs(bbqCoord.first - homeCoord.first) + abs(bbqCoord.second - homeCoord.second);
}