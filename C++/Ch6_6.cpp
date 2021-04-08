#include <iostream>
using namespace std;

class ArrayUtility2
{
public:
	static int* concat(int s1[], int s2[], int size);
	static int* remove(int s1[], int s2[], int size, int& retSize);
};

int* ArrayUtility2::concat(int s1[], int s2[], int size) {
	int sumSize = 2 * size;
	int* s3 = new int[sumSize];
	for (int i = 0; i < sumSize; i++)
	{
		if (i < size)
			s3[i] = s1[i];
		else
			s3[i] = s2[i - size];
	}
	return s3;
}
int* ArrayUtility2::remove(int s1[], int s2[], int size, int& retSize) {
	int* s3 = new int[size];
	int cnt = 0;
	for (int i = 0; i < size; i++)
	{
	int isSame = 0;
		for (int j = 0; j < size; j++)
		{
			if (s1[i] == s2[j])
				isSame = 1;
		}
		if (isSame == 0) {
			s3[i] = s1[i];
			cnt++;
		}
	}
	retSize = cnt;
	return s3;
}

int main(void) {
	int x[5], y[5], count, *z;
	ArrayUtility2 a;
	cout << "정수 5개를 입력하라. 배열 x에 삽입한다.>>";
	for (int i = 0; i < 5; i++)
	{
		cin >> x[i];
	}
	cout << "정수 5개를 입력하라. 배열 y에 삽입한다.>>";
	for (int i = 0; i < 5; i++)
	{
		cin >> y[i];
	}

	cout << "합친 정수 배열을 출력한다" << endl;
	z =	a.concat(x, y, 5);
	for (int i = 0; i < 10; i++)
	{
		cout << z[i] << " ";
	}
	cout << endl;
	a.remove(x, y, 5, count);
	cout << "배열 x[]에서 y[]를 뺀 결과를 출력한다.개수는 " << count << endl;
	
	z = a.remove(x, y, 5, count);
	for (int i = 0; i < count; i++)
	{
		cout << z[i] << " ";
	}
}