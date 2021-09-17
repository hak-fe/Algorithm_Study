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
	deque<int>d;
	int n;
	cin >> n;
	for (int i = n; i >= 1; i--)
	{
		d.push_back(i);
	}
	while (d.size() != 1) {
		// 1. ���� ���� �ִ� ī�带 �ٴڿ� ������.
		d.pop_back(); 
		// 2. ���� ���� �ִ� ī�带 ���� �Ʒ��� �ִ� ī�� ������ �ű��.
		d.push_front(d.back());
		d.pop_back();
	}
	cout << d.front();
}