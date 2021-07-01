#include <iostream>
#include <vector>
using namespace std;

ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

int getDigit(int n) {
	int digit = 0;
	for (int l = n; l != 0; l /= 10)
	{
		digit++;
	}
	return digit;
}

void selfNumber() {
	vector<int>v;
	vector<bool>b(10000, true);
	for (int i = 1; i <= 10000; i++)
	{
		v.push_back(i);
	}

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 1; j <= v[i]; j++)
		{
			int temp = j;
			int sum = j;
			for (int k = 0; k < getDigit(j); k++)
			{
				sum += temp % 10;
				temp /= 10;
			}
			if (v[i] == sum) { // 생성자가 존재한다는 뜻
				b[i] = false;
				break;
			}
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (b[i])
			cout << v[i] << endl;
	}
}

int main() {
	selfNumber();
}