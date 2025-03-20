#include <stdio.h>

int main(void) {

	int input_arr[10]; // 입력받은 수 10개를 저장할 배열
	int r_arr[10]; // 42로 나눈 나머지를 저장할 배열, 반복문으로 다른 값 확인
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