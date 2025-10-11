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
#define INF 2100000000
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int dz[2] = { 1, -1 };

vector<vector<pair<int, int>>>info;
vector<vector<pair<int, int>>>reverse_info;
vector<int>distTemp;
vector<int>distRes;

void djikstraForOrigin(int start);
void djikstraForReverse(int start);
int main() {
	FASTIO;
	int n, m, x, longestTime = 0;
	cin >> n >> m >> x;

	info.assign(n + 1, vector<pair<int, int>>());
	reverse_info.assign(n + 1, vector<pair<int, int>>());
	distTemp.assign(n + 1, INF);
	distRes.assign(n + 1, INF);

	for (int i = 0; i < m; i++)
	{
		int s, e, w;
		cin >> s >> e >> w;
		info[s].push_back({ w, e });
		reverse_info[e].push_back({ w, s });
	}

	djikstraForOrigin(x);
	for (int i = 1; i <= n; i++)
		distRes[i] = distTemp[i];

	distTemp.assign(n + 1, INF);

	djikstraForReverse(x);
	for (int i = 1; i <= n; i++)
		distRes[i] += distTemp[i];

	for (int i = 1; i <= n; i++) {
		if (i == x) continue;
		if (distRes[i] != INF)
			longestTime = max(longestTime, distRes[i]);
	}

	cout << longestTime;
	return 0;
}

void djikstraForOrigin(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int cur_wei = pq.top().first, cur_ver = pq.top().second;
		pq.pop();

		if (distTemp[cur_ver] < cur_wei)
			continue;

		for (pair<int, int> i : info[cur_ver])
		{
			int next_wei = i.first, next_ver = i.second;
			if (distTemp[next_ver] > cur_wei + next_wei) {
				distTemp[next_ver] = cur_wei + next_wei;
				pq.push({ distTemp[next_ver] ,next_ver });
			}
		}
	}
}
void djikstraForReverse(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int cur_wei = pq.top().first, cur_ver = pq.top().second;
		pq.pop();

		if (distTemp[cur_ver] < cur_wei)
			continue;

		for (pair<int, int> i : reverse_info[cur_ver])
		{
			int next_wei = i.first, next_ver = i.second;
			if (distTemp[next_ver] > cur_wei + next_wei) {
				distTemp[next_ver] = cur_wei + next_wei;
				pq.push({ distTemp[next_ver] ,next_ver });
			}
		}
	}
}