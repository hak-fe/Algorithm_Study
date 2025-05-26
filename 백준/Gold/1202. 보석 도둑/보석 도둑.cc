#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#include <tuple>
#include <algorithm>

#define DEBUG 1
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)
#define endl '\n'
using namespace std;
typedef long long int ll;

// 내림차순으로 다시 짤 것!!!!!
/*
	힌트1: 보석이 들어갈 수 있는 가장 작은 가방을 찾기보다,
			가방에 넣을 수 있는 최대 보석을 찾는 방법을 생각해보세요.

---

	힌트2: 더 용량이 큰 가방에 넣을 수 있는 보석에는 용량이
		작은 가방에 넣을 수 있는 보석이 "중복"됩니다.

		처음에 고안했던 방법 + 우선순위 큐 2번 쓰는 방식 하면 풀릴듯?
*/

struct CompareBySecond {
	// a.second < b.second 이면 true를 반환 -> b가 더 높은 우선순위 -> 최대 힙
	bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const {
		return a.second < b.second;
	}
};

int main() {
	FASTIO;

	priority_queue<pair<int, int>, vector<pair<int, int>>, CompareBySecond> pq;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> inputPq;

	vector<int> kWeight;
	ll sum = 0;
	int n, k, m, v, c;

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> m >> v;
		inputPq.push(make_pair(m, v));
	}
	for (int i = 0; i < k; i++) {
		cin >> c;
		kWeight.push_back(c);
	}

	sort(kWeight.begin(), kWeight.end());

	for (int bag_capacity : kWeight)
	{
		while (!inputPq.empty() && bag_capacity >= inputPq.top().first) {
			pq.push(make_pair(inputPq.top().first, inputPq.top().second));
			inputPq.pop();
		}
		if (!pq.empty()) {
			sum += pq.top().second;
			pq.pop();
		}
	}

	cout << sum;

	return 0;
}