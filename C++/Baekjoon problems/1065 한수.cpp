#include<iostream>
using namespace std;

void hansu(int n) {
	if (n <= 99) // 1�� �ڸ��� 10�� �ڸ��� �׳� �Ѽ��� �����. 99������ n ���
		cout << n << endl;
	else {
		int cnt = 99;
		for (int i = 100; i <=n; i++)
		{
			int numCnt = 0;
			for (int j = i; j > 0 ; j/=10) // �ڸ��� Ȯ�� �Ϸ�
			{
				numCnt++;
			}
			int* num = new int[numCnt];
			int temp = i;
			for (int k = numCnt - 1; k >= 0; k--) //Ȯ�� �Ϸ�
			{
				num[k] = temp % 10;
				temp /= 10;
			}
			bool isHanSu = true;
			int* tempNum = new int[numCnt - 1];
			for (int l = 0; l < numCnt - 1; l++) // Ȯ�� �Ϸ�
			{
				tempNum[l] = num[l] - num[l + 1];
			}
			for (int m = 0; m < numCnt - 2; m++)
			{
				if (tempNum[m] != tempNum[m + 1])
					isHanSu = false;
			}
			if (isHanSu)
				cnt++;
		}
		cout << cnt << endl;
	}
}

int main() {
	int n;
	cin >> n;
	hansu(n);
}