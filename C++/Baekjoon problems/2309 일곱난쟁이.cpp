#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool isSeven(int ary[]) {
	int sum = 0;
	for (int i = 0; i < 7; i++)
	{
		sum += ary[i];
	}
	if (sum == 100)
		return true;
	else
		return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int temp[9];
	for (int i = 0; i < 9; i++)
	{
		cin >> temp[i];
	}
	for (int i = 0; i < 9; i++)
	{
		int result[7];
		result[0] = temp[i];
		for (int j = i + 1; j < 9; j++)
		{
			result[1] = temp[j];
			for (int k = j + 1; k < 9; k++)
			{
				result[2] = temp[k];
				for (int l = k + 1; l < 9; l++)
				{
					result[3] = temp[l];
					for (int m = l + 1; m < 9; m++)
					{
						result[4] = temp[m];
						for (int n = m + 1; n < 9; n++)
						{
							result[5] = temp[n];
							for (int o = n + 1; o < 9; o++)
							{
								result[6] = temp[o];
								if (isSeven(result)) {
									sort(result, result + 7);
									for (int i = 0; i < 7; i++)
									{
										cout << result[i] << '\n';
									}
									break;
								}
							}
						}
					}
				}
			}
		}
	}
}