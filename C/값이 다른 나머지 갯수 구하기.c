#include <stdio.h>

int main(void) {

	int input_arr[10]; // �Է¹��� �� 10���� ������ �迭
	int r_arr[10]; // 42�� ���� �������� ������ �迭, �ݺ������� �ٸ� �� Ȯ��
	int cnt = 0;
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &input_arr[i]);
	}

	for (int i = 0; i < 10; i++)
	{
		r_arr[i] = input_arr[i] % 42;
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (r_arr[i] == r_arr[j]) {
			
				r_arr[j] = -j;
			
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (r_arr[i] >= 0) {

		cnt++;

		}
	}

	printf("%d", cnt);

	return 0;
}