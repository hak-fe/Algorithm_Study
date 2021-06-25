#include<iostream>
using namespace std;

void hansu(int n) {
	if (n <= 99) // 1의 자리와 10의 자리는 그냥 한수로 취급함. 99까지는 n 출력
		cout << n << endl;
	else {
		int cnt = 99;
		for (int i = 100; i <=n; i++)
		{
			int numCnt = 0;
			for (int j = i; j > 0 ; j/=10) // 자릿수 확인 완료
			{
				numCnt++;
			}
			int* num = new int[numCnt];
			int temp = i;
			for (int k = numCnt - 1; k >= 0; k--) //확인 완료
			{
				num[k] = temp % 10;
				temp /= 10;
			}
			bool isHanSu = true;
			int* tempNum = new int[numCnt - 1];
			for (int l = 0; l < numCnt - 1; l++) // 확인 완료
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