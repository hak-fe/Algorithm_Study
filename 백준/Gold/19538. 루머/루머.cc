#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#define DEBUG 1
#define SIZE 200001
using namespace std;
typedef long long int ll;
vector<int>connection[SIZE]; //사람 간의 연결관계를 저장하는 벡터
vector<int>result(SIZE, -1); // 결과 출력용 벡터
vector<int>visited(SIZE, 0); //방문 확인용
vector<int>gotBelievedPeople; // 루머를 믿게 된 사람들의 상태를 한꺼번에 변화시키기 위함.
queue<int>mq;// 루머를 믿는 사람의 번호를 저장하고 pop해 사용할 큐

void bfs(int size);
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, temp, m;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		while (1) {
			cin >> temp;
			if (!temp)
				break;
			connection[i].push_back(temp);
		}
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> temp;
		result[temp] = 0;
		visited[temp] = 1;
		mq.push(temp);
	}

	bfs(n);

	for (int i = 1; i <= n; i++)
		cout << result[i] << ' ';

	return 0;
}
void bfs(int size) {
	while (!mq.empty()) {
		int person = mq.front(); //루머를 믿는 사람 한 명을 뽑아 냄
		mq.pop(); // 저장했으니 pop하여 없애줌
		for (int adjacent : connection[person])
		{ //루머를 믿는 사람과 연결되어 있는 사람을 하나 씩 확인함.
			if (visited[adjacent] == 0) { // 그 사람이 아직 루머를 믿지 않는 경우
				int cnt = 0; // 루머를 믿게 되는 상태인지 확인해야 함.
				for (int rumoredpersonOfAdjacent : connection[adjacent]) {
					//adjacent의 주변인들 중 루머를 믿는 사람이 몇 명인지 수를 센다.
					if (result[rumoredpersonOfAdjacent] >= 0)
						cnt++;
				}
				if (cnt >= (connection[adjacent].size() + 1) / 2) {
					// adjacent와 연결된 총 사람 수의 절반이상이 루머를 믿을경우
					//일단 저장해 놓았다가 한꺼번에 상태를 바꿔줘야 한다.
					gotBelievedPeople.push_back(adjacent);
				}
			}
		}
		if (mq.empty()) {
			for (int i = 0; i < gotBelievedPeople.size(); i++)
			{
				visited[gotBelievedPeople[i]] = 1; //방문표시
				result[gotBelievedPeople[i]] = result[person] + 1; // 루머를 전파시킨 사람의 시간 +1 분 해줌.
				mq.push(gotBelievedPeople[i]);// 새로 루머를 믿게 된 사람의 주변사람을 다시 찾아야 하므로 큐에 넣는다.
			}
			gotBelievedPeople.clear(); //새롭게 믿게 될 사람들을 위해 벡터를 비운다.
		}
	}
}