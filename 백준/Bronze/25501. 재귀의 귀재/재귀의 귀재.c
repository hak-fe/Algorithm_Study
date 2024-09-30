#include <stdio.h>
#include <string.h>
int time = 0;
int recursion(const char* s, int l, int r) {
	time++;
	if (l >= r) return 1;
	else if (s[l] != s[r]) return 0;
	else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char* s) {
	return recursion(s, 0, strlen(s) - 1);
}

int main() {
	int n;
	char str[1001];
	scanf(" %d", &n);
	while (getchar() != '\n');

	for (int i = 0; i < n; i++)
	{
		gets(str);
		printf("%d ", isPalindrome(str));
		printf("%d\n", time);
		time = 0;
	}
	return 0;
}