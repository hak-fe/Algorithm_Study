#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, min = 64;
	cin >> x;
	vector<int>v;
	v.push_back(64); //ó������ 64cm ���� �ϳ��� ������ �ִ�.
	while (true) {
		int sum = 0;
		for (int i = 0; i < v.size(); i++)
		{
			sum += v[i];
		}
		if (sum > x) { //�̶�, ���� X���� ũ�ٸ�, �Ʒ��� ���� ������ �ݺ��Ѵ�.
			sort(v.begin(), v.end());
			// 1. ������ �ִ� ���� �� ���̰� ���� ª�� ���� �������� �ڸ���.
			// 2. ����, ������ �ڸ� ������ ���� �� �ϳ��� ������ �����ִ� ������ ������ ���� X���� ũ�ų� ���ٸ�, 
			//	������ �ڸ� ������ ���� �� �ϳ��� ������.
			v[0] /= 2;
			if (sum - v[0] >= x)
				continue;
			else
				v.push_back(v[0]);
		}
		else
			break;
	}
	sort(v.begin(), v.end());
	int sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		sum += v[i];
		if (sum == x) {
			cout << i + 1;
			break;
		}
	}
}