#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#define DEBUG 0
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 }; //우하좌상순
using namespace std;
typedef long long int ll;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, temp, cnt = 1;
	while (1)
	{
		cin >> n;
		if (n == 0)
			break;
		queue<int> qx;
		queue<int> qy;
		vector<vector<int>>map(n);
		vector<vector<int>>result(n, vector<int>(n, -1));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> temp;
				map[i].push_back(temp);
			}
		}
		result[0][0] = map[0][0];
		qx.push(0);
		qy.push(0);

		while (!qx.empty())
		{
			int i = qx.front();
			int j = qy.front();
			qx.pop();
			qy.pop();
			for (int k = 0; k < 4; k++)
			{
				if (i + dy[k] < n && i + dy[k] >= 0 && j + dx[k] < n && j + dx[k] >= 0) {
					int x = i + dy[k], y = j + dx[k];
					if (result[x][y] == -1) {
						result[x][y] = result[i][j] + map[x][y];
						qx.push(x);
						qy.push(y);
						if (DEBUG) {
							cout << "현재 위치 : " << i << ", " << j << '\n';
							cout << x << ", " << y << "값이 " << result[i][j] + map[x][y] << "로 갱신됨\n";
							cout << x << ", " << y << "좌표가 큐에 저장됨.\n";
						}
					}
					else if (result[i][j] + map[x][y] < result[x][y]) {
						result[x][y] = result[i][j] + map[x][y];
						qx.push(x);
						qy.push(y);
						if (DEBUG) {
							cout << "현재 위치 : " << i << ", " << j << '\n';
							cout << x << ", " << y << "값이 " << result[i][j] + map[x][y] << "로 갱신됨\n";
							cout << x << ", " << y << "좌표가 큐에 저장됨.\n";
						}
					}
					if (DEBUG) {
						for (int p = 0; p < n; p++)
						{
							for (int q = 0; q < n; q++)
							{
								cout << result[p][q] << ' ';
							}
							cout << '\n';
						}
						cout << '\n';
					}
				}
			}
		}
		cout << "Problem " << cnt << ": " << result[n - 1][n - 1] << '\n';
		cnt++;
	}
	return 0;
}