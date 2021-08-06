#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, giho1, result = 0;
	bool isFirstBiggest = true;
	vector<int> hubo;
	cin >> n >> giho1;
	
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}

	for (int i = 0; i < n - 1; i++)
	{
		int temp;
		cin >> temp;
		if (temp >= giho1) { // ��ȣ 1������ ũ�ų� ���� ���� ���Ϳ� ������.
			hubo.push_back(temp);
			isFirstBiggest = false;
		}
	}
	if (isFirstBiggest) {
		cout << 0 << '\n';
		return 0;
	}
	sort(hubo.begin(),hubo.end(),greater<>()); // Ȯ�� �Ϸ�

	while (true) {
		isFirstBiggest = true;
		hubo[0]--;
		giho1++;
		result++;
		sort(hubo.begin(), hubo.end(), greater<>()); // Ȯ�� �Ϸ�
		for (int i = 0; i < hubo.size(); i++)
		{
			if (hubo[i] >= giho1)
				isFirstBiggest = false;
		}
		if (isFirstBiggest) {
			cout << result << endl;
			break;
		}
	}
}