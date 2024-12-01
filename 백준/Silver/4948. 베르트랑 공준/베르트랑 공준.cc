#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;
int prime[246913];
void getPrime();
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, temp, cnt;
	fill(prime, prime + 246913, 1);
	prime[1] = 0;
	getPrime();
	while (1) {
		cnt = 0;
		cin >> n;
		if (n == 0)
			return 0;
		for (ll i = n+1; i <= 2 * n; i++)
			if (prime[i] == 1)
				cnt++;
		cout << cnt << '\n';
	}
	return 0;
}
void getPrime() {
	for (int i = 2; i * i <= 246912; i++)
	{
		for (int j = i * i; j <= 246912; j += i)
		{
			if (prime[j])
				prime[j] = 0;
		}
	}
}