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

	int crain,box; // ũ���� ��, box ��
	vector<int>crainLimit;// ũ���� ���� ����
	vector<int>boxWeight;// �ڽ� ����

	cin >> crain;
	for (int i = 0; i < crain; i++)
	{
		int temp;
		cin >> temp;
		crainLimit.push_back(temp);
	}
	cin >> box;
	for (int i = 0; i < box; i++)
	{
		int temp;
		cin >> temp;
		boxWeight.push_back(temp);
	}
	sort(crainLimit.begin(), crainLimit.end(), greater<>());
	sort(boxWeight.begin(), boxWeight.end(), greater<>());
	// ũ���� ���� ���Ѻ��� ū �ڽ��� �����Ѵٸ� -1 ���
	bool overlimit = false;
	for (int i = 0; i < box; i++)
	{
		if (boxWeight[i] > crainLimit[0]) {
			overlimit = true;
			break;
		}
	}
	if (overlimit)
		cout << -1;
	else {
	
	
	}
}