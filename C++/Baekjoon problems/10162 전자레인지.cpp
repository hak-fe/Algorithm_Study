#include <iostream>
using namespace std;

int main() {

	int time;
	cin >> time;
	int ary[3] = { 0, };
	// A�� 5��, B�� 1��, C�� 10��
	// �ʴ����� ��� �ٲٸ�
	//300��, 60�� 10��
	// ���� 10�� ����̹Ƿ�, time�� 10���� ������ �������� ������
	// -1�� ����Ѵ�. -> �ð��� ��Ȯ�� ���� �� ���� ����
	// �� �ܴ̿� ���ʴ�� ����
	if (time % 10 == 0) {
		if (time / 300 > 0) {
			ary[0] += time / 300;
			time -= 300 * ary[0];
			if (time <= 0) {
				for (int i = 0; i < 3; i++)
				{
					cout << ary[i] << " ";
				}
			}	
		}
		if (time / 60 > 0) {
			ary[1] += time / 60;
			time -= 60 * ary[1];
			if (time <= 0) {
				for (int i = 0; i < 3; i++)
				{
					cout << ary[i] << " ";
				}
			}
		}
		if (time / 10 > 0 ){
			ary[2] += time / 10;
			time -= 10 * ary[2];
			if (time <= 0) {
				for (int i = 0; i < 3; i++)
				{
					cout << ary[i] << " ";
				}
			}
		}
	}
	else
		cout << -1 << endl;
}