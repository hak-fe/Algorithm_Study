#include <stdio.h>

int main()
{

	int H, M, S, want_sec;
	scanf("%d%d%d%d", &H, &M, &S, &want_sec);

	S += want_sec;												

		M += S / 60;
		S = S % 60;
	
		H += M / 60;
		M = M % 60;
	
		H %= 24;

	printf("%d %d %d", H, M, S);

	return 0;
	}