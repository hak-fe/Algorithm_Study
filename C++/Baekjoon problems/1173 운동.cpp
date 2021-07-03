#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, T, R, m, M, tranningTime = 0, result = 0, ori_m; 

	cin >> N >> m >> M >> T >> R;
	ori_m = m;
	if (T > M - m)
		cout << -1 << '\n';
	else {
		while (true) {
			if (tranningTime == N)
				break;
			if (m + T <= M) { //현재 맥박에서 증가량을 더해도 한계 이하면?
				m += T; // 맥박을 더해줌
				tranningTime++;
				result++; // 시간 1분 증가
			}
			else{ // 한계 이상일 경우 -> 휴식해야함
				m -= R;
				result++;
				if (m < ori_m) // 현재 맥박이 원래 맥박보다 작으면 원래 맥박으로 값 변경,
					m = ori_m; // 맥박은 원래 맥박이 된다..
			}
		}
		cout << result << '\n';
	}
}
