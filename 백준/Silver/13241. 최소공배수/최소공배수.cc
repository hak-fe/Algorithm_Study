#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;
ll func(ll max, ll min);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll a, b;
	cin >> a >> b;
	if (a == 0 || b == 0)
		cout << 0;
	else
		cout << func(max(a, b), min(a, b));
	return 0;
}
// a와 b의 최소공배수는 
// a와 b의 곱을 a와 b의 최대공약수로 나눈 것과 같다.
ll func(ll max, ll min) {
	ll a = max, b = min, tmp, gcd;
	while (b != 0)
	{
		tmp = a;
		a = b;
		b = tmp % b;
	}
	gcd = a;
	return max * min / gcd;
}