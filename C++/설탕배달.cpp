#include <iostream>
using namespace std;

int main(void) {

	int N = 0, isFinish = 0;
	int cnt5 = 0, cnt3 = 0; // 5�� 3�� ������ �� ����
	cnt5 = 0;
	cnt3 = 0;
	cin >> N; //���� ����
	int ori_N = N; // ������ N���� ������ ����
	// �Ʒ��� ������ ���, ������ ������ ���� Ƚ���� ����ϰ� ������ �ȴ�.
	//1. ���ʿ� 5�� ������ �������� ��� -> ���� ���� Ƚ��
	//2. 5�� 3���� �����Ͽ� ������ �������� ��� -> 2��°�� ���� Ƚ��
	//3. 3���θ� ������ �������� ��� -> 3��°�� ���� Ƚ��
	//4. �� 3������ �ش���� �ʴ� ��� -> -1 ���

	//1.  5�� ������ �������� ���
	if (N % 5 == 0) {
		cout << N / 5<< endl;
		isFinish = 1;
	}
	N = ori_N;
	//2-1 5�� �����ٰ� 3���� ������ ���
	while (isFinish == 0) {
		N -= 5;
		cnt5++;
		if (cnt5 == 1 && N < 3)
			break;
		if (N % 3 == 0 && N % 5 != 0) {
			cnt3 += N / 3;
			isFinish = 1;
			cout << cnt5 + cnt3 << endl;
			break;
		}
		if (N <= 0 || N < 3)
			break;
	}
	N = ori_N;
	cnt5 = 0;
	cnt3 = 0;
	//2-2 3���� �����ٰ� 5�� ������ ���
	while (isFinish == 0) {
		N -= 3;
		cnt3++;
		if (cnt3 == 1 && N < 5)
			break;
		if (N % 5 == 0 && N % 3 != 0) {
			cnt5 += N / 5;
			isFinish = 1;
			cout << cnt5 + cnt3 << endl;
			break;
		}
		if (N <= 0 || N < 5)
			break;
	}
	N = ori_N;
	cnt5 = 0;
	cnt3 = 0;
	//3. 3���θ� ������ �������� ���
	if (isFinish == 0 && N % 3 == 0) {
		cout << N / 3 << endl;
		isFinish = 1;
	}
	N = ori_N;
	//4. �Ǵ� ��찡 ���� �� -1 ���
	if (isFinish == 0) {
		cout << "-1" << endl;
	}
}