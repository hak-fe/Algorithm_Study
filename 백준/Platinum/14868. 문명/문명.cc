#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>

#define DEBUG 1
#define endl '\n'
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)
#define DIV 10007
#define MAX 2001
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int space[MAX][MAX]; // map
short visited[MAX][MAX]; //방문 확인용
vector<pair<int, int>>civils; //문명 좌표
vector<int> orderOfCivils; // 문명 순서 (unionfind용)

int initialCheck(int mapSize, int sizeOfCivils);
void bfs(int mapSize, int sizeOfCivils);
void printMap(int n);
int allConnectedCheck(int sizeOfCivils);
int find_civ(int i);
void union_civ(int a, int b);

int main() {
	int n, k, x, y;
	cin >> n >> k;

	civils.push_back(make_pair(-1, -1));
	orderOfCivils.push_back(0);

	for (int i = 0; i < k; i++)
	{
		cin >> x >> y;
		civils.push_back(make_pair(x, y));
		visited[x][y] = 1;
	}

	for (int i = 1; i <= k; i++) {
		orderOfCivils.push_back(i);
		x = civils[i].first, y = civils[i].second;
		space[x][y] = i;
	}

	if (k >= n * n) {
		cout << 0;
		return 0;
	}

	if (initialCheck(n, k)) { // 초기에 모든 문명이 연결되어 있는 상태인가?
		cout << 0; //그렇다면 0년 출력
		return 0;
	}
	// 아니면 BFS 돌며 찾기

	bfs(n, k);

}

int initialCheck(int mapSize, int sizeOfCivils) {
	for (int i = 1; i <= sizeOfCivils; i++) {
		int x = civils[i].first;
		int y = civils[i].second;

		for (int j = 0; j < 4; j++) {
			int nx = x + dx[j];
			int ny = y + dy[j];

			if (nx < 1 || nx > mapSize)	continue;
			if (ny < 1 || ny > mapSize)	continue;

			if (space[nx][ny] != 0) {
				union_civ(space[x][y], space[nx][ny]);
			}
		}
	}
	return allConnectedCheck(sizeOfCivils);
}
void bfs(int mapSize, int sizeOfCivils) {
	queue<pair<int, int>>q, tempQ;
	for (int i = 1; i <= sizeOfCivils; i++)
	{
		q.push(make_pair(civils[i].first, civils[i].second));
	}

	for (int year = 1; ; year++)
	{
		while (!q.empty()) {
			int x = q.front().first, y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i], ny = y + dy[i];
				if (nx < 1 || nx > mapSize)	continue;
				if (ny < 1 || ny > mapSize)	continue;
				if (!visited[nx][ny]) {
					visited[nx][ny] = 1;
					space[nx][ny] = space[x][y];
					tempQ.push(make_pair(nx, ny));
				}
			}
		}
		q = tempQ;
		while (!tempQ.empty()) {
			int x = tempQ.front().first, y = tempQ.front().second;
			tempQ.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i], ny = y + dy[i];
				if (nx < 1 || nx > mapSize)	continue;
				if (ny < 1 || ny > mapSize)	continue;
				if (space[nx][ny] != 0) {
					union_civ(space[x][y], space[nx][ny]);
				}
			}
		}

		if (allConnectedCheck(sizeOfCivils)) {
			cout << year << endl;
			return;
		}
	}
	return;
}
void printMap(int n) {
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) {
			cout << space[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
int allConnectedCheck(int sizeOfCivils) {
	int root = find_civ(1);
	for (int i = 2; i <= sizeOfCivils; i++)
	{
		if (root != find_civ(i))
			return 0;
	}
	return 1;
}
int find_civ(int i) {
	if (orderOfCivils[i] == i)
		return i;

	return orderOfCivils[i] = find_civ(orderOfCivils[i]);
}
void union_civ(int a, int b) {
	int rootA = find_civ(a);
	int rootB = find_civ(b);

	if (rootA != rootB) {
		if (rootA < rootB)
			orderOfCivils[rootB] = rootA;
		else
			orderOfCivils[rootA] = rootB;
	}
}