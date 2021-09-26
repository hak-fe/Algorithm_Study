#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
typedef unsigned long long int ll;

int Bsearch(ll ary[], int size, ll findingNum)  // ����Ž�� �ҽ�
{
	int start = 0; // ���� �ε���
	int end = size - 1; // �� �ε���
	int mid = 0; // �߰� �ε���
	while (start <= end)
	{
		/*if (ary[start] < findingNum && ary[end] < findingNum)
			return 0;*/
		mid = (start + end) / 2; // ã�� �ִ� �κ��� �߰� �ε����� �־��� 
		if (ary[mid] == findingNum) // ã���� �ϴ� ���� �߰��ϸ� 1 ����
			return 1;
		else // ���ϴ� ���� �߰� ���ߴٸ�?
		{
			if (ary[mid] < findingNum) // ���� ã�� ���� ã���� �ϴ� �� ���� ���� ���
				start = mid + 1;
			// start �ε����� mid + 1�� �ٲ۴�. -> ū ������ �δ�.
			//ex) 1,2,3,4,5,6,7 �� ����ְ�, 5�� ã�ƾ� �ϴµ�, 4�� ã�Ҵٸ�?
			// 1���� 4 ������ �Ⱥ��� �Ǵϱ�, start�� 5���� �����ϵ��� �ٲ۴�.
			else if (ary[mid] > findingNum) // ���� ã�� ���� ã���� �ϴ� �� ���� Ŭ ���
				end = mid - 1;
			//������ �� �Ͱ� �ݴ��, �̹����� end�� ������ ����.
			//ex) 1,2,3,4,5,6,7 �� ����ְ�, 2�� ã�ƾ� �ϴµ�, 4�� ã�Ҵٸ�?
			// 4���� 7 ������ �Ⱥ��� �Ǵϱ�, end�� 3���� �����ϵ��� �ٲ۴�.
		}
	}
	return 0; // while�� ���Ƶ� �� ã�´ٸ� 0���
}

int main()
{
	int n, m;
	cin >> n;
	ll* firstAry = new ll[n];
	for (int i = 0; i < n; i++)
		cin >> firstAry[i];
	sort(firstAry, firstAry + n);
	cin >> m;
	ll* secondAry = new ll[m];
	for (int i = 0; i < m; i++)
		cin >> secondAry[i];

	for (int i = 0; i < m; i++)
	{
		cout << Bsearch(firstAry, n, secondAry[i]) << '\n';
	}
}