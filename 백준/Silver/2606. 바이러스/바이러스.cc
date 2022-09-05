#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <deque>
#include <utility>

#define MIN 0
#define MAX 10000000

using namespace std;
typedef unsigned long long int ll;

vector<int> graph[101];
bool infected[101] = { false, };

void dfs(int x);
int cnt = 0;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//DFS 사용

	int com; // 컴퓨터 수
	int pair; // 연결된 컴퓨터 쌍의 수
	cin >> com >> pair;
	for (int i = 1; i <= pair; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	infected[1] = true;
	dfs(1);
	cout << cnt << '\n';
}

void dfs(int x) 
{
	infected[x] = true; // 감염됨
	for (int i = 0; i < graph[x].size(); i++) // x번 컴퓨터와 연결된 수 만큼 반복
	{
		int temp = graph[x][i]; // x번 컴퓨터와 연결된 컴퓨터의 번호가 들어감
		if (!infected[temp]) {// x번 컴퓨터와 연결되었는데, 감염 표시가 안되었다면
			dfs(temp);
			cnt++;
		}
		// 감염됐음을 표시하고, graph[temp]와 연결된 
		//또 다른 그래프가 있는지 확인하기 위해 재귀
	}
}