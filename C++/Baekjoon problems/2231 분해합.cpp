#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int min = 1000001;
	bool itHasMin = false;
	for (int i = 1; i <= n; i++) //i�� �� �����ڴ�.
	{
		bool istrue = false;
		int result = 0; // �����ڸ� ������ ����
		int digit = 0; // �ڸ��� ������ ����
		for (int j = i; j != 0; j/=10) // �ڸ��� ���ϱ�
		{
			digit++;
		}
		result += i; // �������� �ڱ��ڽ��� ���� ���ؾ� �ϹǷ� i�� ����.
		int temp = i; // �ڸ��� ������ŭ �߶� ���ϱ� ���� i�� ���� temp����
		for (int k = 0; k < digit; k++) // �ڸ�����ŭ ������ ���ϴ� �ݺ���
		{
			result += temp % 10; // i�� 10���� ���� �������� ����
			temp /= 10; // ���� ��, 10���� ���� ���� �ٽ�����
		}
		if (result == n) { // �Է¹��� ��������, ���� ���� �����հ� ������
			result = i; // result�� i���� �־���
			istrue = true;
		}
		if (result < min && istrue) {//���� ���� �����ڸ� ���ؾ� �ϹǷ�
			min = result;
			itHasMin = true;
		}
	}
	if (itHasMin)
		cout << min <<endl;
	else
		cout << 0 << endl;
}