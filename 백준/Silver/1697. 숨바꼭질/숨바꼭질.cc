#define INF 1000000000
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>;
using namespace std;
int visited[100001];
int weights[100001];

int bfs(int subin, int dongsaeng);

int main() {
	int subin, dongsaeng, res;
	cin >> subin >> dongsaeng;
	for (int i = 0; i <= 100000; i++)
		weights[i] = INF;
	res = bfs(subin, dongsaeng);
	cout << res;
	return 0;
}
int bfs(int subin, int dongsaeng) {
	int n = subin;
	queue<int> q;
	q.push(n);
	visited[n] = 1; // 수빈이 있는 지점 방문처리
	weights[n] = 0; // 수빈이가 있는 지점은 시간이 0초임
	if (subin > dongsaeng) // 수빈이가 동생보다 앞에 있으면 x-1 방법 밖에 없음.
		return subin - dongsaeng;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		if (temp - 1 <= 100000 && (temp - 1) * 2 >= subin) {
			if (visited[temp - 1] == 0 || weights[temp - 1] > weights[temp] + 1) {
				q.push(temp - 1);
				visited[temp - 1] = 1;
				weights[temp - 1] = weights[temp] + 1;
			}
		}
		if (temp + 1 <= 100000) {
			if (visited[temp + 1] == 0 || weights[temp + 1] > weights[temp] + 1) {
				q.push(temp + 1);
				visited[temp + 1] = 1;
				weights[temp + 1] = weights[temp] + 1;
			}
		}
		if (2 * temp <= 100000) {
			if (visited[2 * temp] == 0 || weights[2 * temp] > weights[temp] + 1) {
				q.push(2 * temp);
				visited[2 * temp] = 1;
				weights[2 * temp] = weights[temp] + 1;
			}
		}
	}
	return weights[dongsaeng];
}