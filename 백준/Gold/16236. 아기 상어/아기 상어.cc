#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#include <tuple>

#define DEBUG 0
#define SIZE 2001
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)
#define endl '\n'
#define BABYSHARK 9
using namespace std;
typedef long long int ll;

int dy[4] = { -1, 0, 0, 1 };
int dx[4] = { 0, -1, 1, 0 }; // 상좌우하 순

vector<vector<int>>space;
vector<vector<int>>visited;
vector<vector<int>>dist;

int sizeOfShark = 2, killCount = 0, result = 0;

void bfs(int x, int y, int size);
void printSpace(int size);

struct cmp {
	bool operator()(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
		if (get<2>(a) != get<2>(b)) // 먼저 c 비교
			return get<2>(a) > get<2>(b); // c가 작을수록 우선
		if (get<0>(a) != get<0>(b)) // c가 같다면 a 비교
			return get<0>(a) > get<0>(b); // a가 작을수록 우선
		return get<1>(a) > get<1>(b); // a도 같다면 b 비교
	}
};

int main() {
	FASTIO;
	int n, x, y;
	cin >> n;
	space.assign(n + 1, vector<int>(n + 1));
	visited.assign(n + 1, vector<int>(n + 1, 0));
	dist.assign(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) {
			cin >> space[i][j];
			if (space[i][j] == 9) {
				visited[i][j] = 1;
				x = i;
				y = j;
			}
		}
	}
	bfs(x, y, n);
	cout << result;
	return 0;
}
void bfs(int x, int y, int size) {
	priority_queue<tuple<int,int,int>, vector<tuple<int, int, int>>, cmp> pq;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		int sharkX = q.front().first, sharkY = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tempX = sharkX + dy[i], tempY = sharkY + dx[i];
			if (tempX >= 1 && tempX <= size &&
				tempY >= 1 && tempY <= size) {
				if (space[tempX][tempY] <= sizeOfShark  && !visited[tempX][tempY]) {
					q.push(make_pair(tempX, tempY));
					visited[tempX][tempY] = 1;
					dist[tempX][tempY] = dist[sharkX][sharkY] + 1;
					if(space[tempX][tempY] < sizeOfShark && space[tempX][tempY]!= 0)
						pq.push(make_tuple(tempX, tempY, dist[tempX][tempY]));
				}
			}
		}
	}
	if (!pq.empty()) {
		int tempx = get<0>(pq.top()), tempy = get<1>(pq.top());
		if (DEBUG) cout << tempx << ", " << tempy << "에서 물고기 발견\n";
		if (DEBUG) cout << "증가 전 result : " << result << '\n';
		if (DEBUG) cout << "물고기 사이즈 : " << space[tempx][tempy] << ", 상어 사이즈 : " << sizeOfShark << '\n';

		killCount++;
		if (sizeOfShark == killCount) {
			sizeOfShark++;
			killCount = 0;
		}
		if (DEBUG) cout << " 먹고 난 후 상어 사이즈 : " << sizeOfShark << '\n';
		result += dist[tempx][tempy];
		if (DEBUG) cout << "증가 후 result : " << result << '\n';
		dist.assign(size + 1, vector<int>(size + 1, 0));
		visited.assign(size + 1, vector<int>(size + 1, 0));
		visited[tempx][tempy] = 1;
		space[tempx][tempy] = 9;
		space[x][y] = 0;
		if (DEBUG) printSpace(size);
		bfs(tempx, tempy, size);
		return;
	}
}
void printSpace(int size) {
	cout << '\n';
	for (int i = 1; i <= size; i++)
	{
		for (int j = 1; j <= size; j++)
		{
			cout << space[i][j];
		}
		cout << '\n';
	}
	cout << '\n';
}