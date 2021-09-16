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

int ary[10000] = {};

int main()
{
	/*
	������ : N���� ������ ���� N���� ���� ��
	�߾Ӱ� : N���� ������ �����ϴ� ������ �������� ��� �� �߾ӿ� ��ġ�ϴ� ��
	�ֺ� : N���� ���� �� ���� ���� ��Ÿ���� ��
	���� : N���� ���� �� �ִ񰪰� �ּڰ��� ����
	*/
	int n, temp, sum = 0, frequent = 0;
	vector<int>v; // ������, �߾Ӱ�, ���� ���� �� ����ϴ� ����
	vector<int>v2; // �ֺ� ���� �� ����ϴ� ����
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		sum += temp;
		v.push_back(temp);
		ary[temp + 4000]++;
	}
	sort(v.begin(), v.end());
	// ������
	cout << floor((double)sum / n + 0.5) << '\n';
	//�߾Ӱ�
	cout << v[n / 2] << '\n';
	//�ֺ�
	for (int i = 0; i <= v.back() + 4000; i++) {
		if (ary[i] > frequent)
			frequent = ary[i];
	}
	for (int i = 0; i <= v.back() + 4000; i++) {
		if (frequent == ary[i])
			v2.push_back(i - 4000);
	}
	sort(v2.begin(), v2.end());
	if (v2.size() == 1)
		cout << v2[0] << '\n';
	else
		cout << v2[1] << '\n';
	//����
	cout << v.back() - v.front() << '\n';
}
