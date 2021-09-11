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

int main() 
{
	stack<int>st;
	int n, num;

	cin >> n;

	int* ary = new int[n]; // ������ ���� �迭 ����
	int* result = new int[n]; // ��� ��� �迭 ����

	for (int i = 0; i < n; i++)
	{
		cin >> ary[i]; // ���� �Է�
	}
	// �߿��� �� - ���⼭ ������ ������ �Ųٷ� Ž���ϸ� ��ū���� ã���ִ� ������ ��.
	for (int i = n - 1; i >= 0; i--)
	{
		while (!st.empty() && st.top() <= ary[i])
			// ���� �ȿ� ���� �����ϰ�, ������ ���κ��� ���� ������ ��,
			st.pop(); // �� ���� ��ū���� �� �� �����Ƿ� ������ �˽�Ŵ.

		if (st.empty()) 
			// ������ ��������� ��ū���� ���ٴ� ���̹Ƿ�
			// ������ �ε����� ��� �迭�� -1�� �־���
			result[i] = -1;
		else
			// else�� ���� �ش� ������ ���κ��� ary[i]�� ��ū����� ���̹Ƿ�
			// ������ �ε����� ������ ��� �迭�� ���� ������ top(��ū��)�� �־���
			result[i] = st.top();

		st.push(ary[i]); // ���� ��ū���� ã�� ���� ary[i] ���� ���ÿ� Ǫ��
	}
	for (int i = 0; i < n; i++)
	{
		cout << result[i] << ' ';
	}
	delete[] ary;
	delete[] result;
}