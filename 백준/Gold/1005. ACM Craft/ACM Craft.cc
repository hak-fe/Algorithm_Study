#include<bits/stdc++.h>
using namespace std;

#define MAX 2100000000
#define DIV 1000000007
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL)
#define endl '\n'

typedef unsigned long long ull;
typedef long long ll;


int main() {
	FASTIO;

	int t, n, k, x, y, w;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		vector<int>delay(n + 1);
		vector<int>prefixSum(n + 1, 0);
		vector<vector<int>>graph(n + 1);
		vector<int>inDegree(n + 1, 0);

		for (int i = 1; i <= n; i++)
			cin >> delay[i];
		for (int i = 0; i < k; i++)
		{
			cin >> x >> y;
			graph[x].push_back(y);
			inDegree[y]++;
		}
		cin >> w;

		queue<int>q;
		for (int i = 1; i <= n; i++)
			if (!inDegree[i]) {
				q.push(i);
				prefixSum[i] = delay[i];
			}
		
		while (!q.empty()) {
			int current = q.front();
			q.pop();
			for (int next : graph[current]) {
				prefixSum[next] = max(prefixSum[next], delay[next] + prefixSum[current]);
				if (!--inDegree[next])
					q.push(next);
			}
		}
		cout << prefixSum[w] << endl;
	}



	return 0;
}