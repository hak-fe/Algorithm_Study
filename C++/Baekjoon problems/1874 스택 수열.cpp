#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <stack>
using namespace std;

int main() {

	stack<int>s;
	vector<char>result;
	int cnt = 1; // 1���� n���� ������ ��
	int n; // �ݺ� Ƚ��
	cin >> n;

	while (n--) {
	
		int x; // ������ �Է¹��� ����
		cin >> x;

		while (cnt <= x) // ī��Ʈ�� ������ �� ���ϸ� 
		{
			s.push(cnt); // cnt�� ���ÿ� ����
			cnt += 1;// �� 1 ����
			result.push_back('+'); // pushback ������ result ���Ϳ� + ���� ����
		}
		if (s.top() == x) 
		// �� �ݺ������� cnt�� s�� ��� �ִٰ� Ż��Ǹ� s�� ���κа� x �� ����.
		// ���ٸ�, s���� ����� result�� - �Է�
		{
			s.pop();
			result.push_back('-');
		}
		else
		// �ٸ��� �־��� ������ �ٸ��Ƿ� no�� ����ϰ� ���α׷� ����
		{
			cout << "NO";
			return 0;
		}
	}
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << '\n';
	}
}