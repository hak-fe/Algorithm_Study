#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int visited[50][50];
int island[50][50];
int cnt;
int w, h;
void dfs(int x, int y);
int main() {
	for (;;) {
		cin >> w >> h;
		if (w == 0 && h == w)
			return 0;

		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> island[i][j];

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++) {
				if (island[i][j] == 1 && visited[i][j] == 0) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++) {
				visited[i][j] = 0;
				cnt = 0;
			}
	}
}
void dfs(int x, int y) {
	if (x < 0 || y < 0 || x >= h || y >= w)
		return;
	if (island[x][y] == 1 && visited[x][y] == 0) {
		visited[x][y] = 1;
		dfs(x, y - 1); // 서
		dfs(x - 1, y - 1); // 북서
		dfs(x - 1, y); //북
		dfs(x - 1, y + 1); //북동
		dfs(x, y + 1); // 동
		dfs(x + 1, y + 1); // 남동
		dfs(x + 1, y); // 남
		dfs(x + 1, y - 1); // 남서
	}
}