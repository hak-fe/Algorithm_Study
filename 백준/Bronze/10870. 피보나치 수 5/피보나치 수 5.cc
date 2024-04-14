#include <stdio.h>

int FibonacciNum(int n);

int main(void) {

	int a = 0;
	scanf("%d", &a);

	printf("%d", FibonacciNum(a));

	return 0;
}

int FibonacciNum(int n) {
	
	if (n == 0) {	// Tip. 가장 아래 층을 if로 정의해 놓아야 한다.
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		return FibonacciNum(n - 1) + FibonacciNum(n - 2);
	}
}