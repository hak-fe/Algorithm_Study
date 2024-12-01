#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#define MAX 1000001
using namespace std;
typedef long long int ll;
int prime[MAX];
void getPrime();
int gold(int n);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, temp, cnt;
	fill(prime, prime + MAX, 1);
	prime[1] = 0;

	getPrime();

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		cout << gold(temp) << '\n';
	}
	return 0;
}
int gold(int n) {
	int cnt = 0;
	for (int i = 2; i <= n/2; i++)
	{
		if (prime[i] == 1 && prime[n - i])
			cnt++;
	}
	return cnt;
}
void getPrime() {
	for (int i = 2; i * i < MAX; i++)
	{
		for (int j = i * i; j < MAX; j += i)
		{
			if (prime[j])
				prime[j] = 0;
		}
	}
}