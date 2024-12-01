#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;

ll isPrime(ll num);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, temp;
	cin >> n;
	for (ll i = 0; i < n; i++)
	{
		cin >> temp;
		if (temp == 0 || temp == 1)
			cout << 2 << '\n';
		else
			cout << isPrime(temp) << '\n';
	}
	return 0;
}
ll isPrime(ll num) {
	while (1) {
		int isPrime = 1;
		for (ll i = 2; i * i <= num; i++)
		{
			if (num % i == 0) {
				isPrime = 0;
				break;
			}
		}
		if (isPrime)
			return num;
		num++;
	}
}