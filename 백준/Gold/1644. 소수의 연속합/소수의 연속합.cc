#include<bits/stdc++.h>
using namespace std;

#define MAX 4000000
#define DIV 1000000007
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL)
#define endl '\n'

typedef unsigned long long ull;
typedef long long ll;

vector<bool>isPrime(MAX + 1, 1);
vector<int>prime;
void chaeOfEra() {
	for (int i = 2; i * i <= MAX; i++)
	{
		if (isPrime[i] == 0) continue;
		for (int j = i * i; j <= MAX; j += i) {
			isPrime[j] = 0;
		}
	}
}

int main() {
	FASTIO;
	int n, cnt = 0;
	cin >> n;
	chaeOfEra();
	for (int i = 2; i <= n; i++)
	{
		if (isPrime[i]) {
			prime.push_back(i);
		}
	}
	ll sum = 0;
	int s = 0, e = 0;
	while (e < prime.size() && e >= s) {
		if (sum < n) {
			sum += prime[e];
			if (e + 1 < prime.size()) 
				e++;
		}
		else if (sum > n) {
			sum -= prime[s++];
		}
		else {
			cnt++;
			sum -= prime[s++];
		}
		//cout << "s : " << s << ", e : " << e << " : " << sum << endl;
	}


	cout << cnt;
	return 0;
}