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
			if (m + T <= M) { //���� �ƹڿ��� �������� ���ص� �Ѱ� ���ϸ�?
				m += T; // �ƹ��� ������
				tranningTime++;
				result++; // �ð� 1�� ����
			}
			else{ // �Ѱ� �̻��� ��� -> �޽��ؾ���
				m -= R;
				result++;
				if (m < ori_m) // ���� - ���ҷ����� ��, �������� ������,
					m = ori_m; // �ƹ��� m�� �ȴ�.
			}
		}
		cout << result << '\n';
	}
}