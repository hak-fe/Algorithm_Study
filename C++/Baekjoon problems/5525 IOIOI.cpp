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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, length, result = 0;
	string str;
	cin >> n >> length >> str;

	for (int i = 0; i < length; i++)
	{
		int temp = 0;
		if (str[i] == 'I')
		{
			while (str[i + 1] == 'O' && str[i + 2] == 'I')
			{
				i += 2;
				temp++;
				if (temp == n)// temp k���� P(n) �� ���� ��
				{
					temp--;   // �ߺ� ����
					result++; // ����, P(n)�� str�� ���Եƴٴ� �ǹ��̹Ƿ� ����� 1����
				}
			}
		}
	}
	cout << result;
}