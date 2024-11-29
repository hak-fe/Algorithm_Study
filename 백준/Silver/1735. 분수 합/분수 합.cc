#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;
ll getLcd(ll max, ll min);
ll getGcd(ll max, ll min);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// a / b
	// c / d
	int a, b, c, d, sumOfNumerator, gcd;
	cin >> a >> b >> c >> d;
	// 1. 분모의 최소 공배수 구하기
	int lcd = getLcd(max(b, d), min(b, d));
	// 2. 각 분자를 분모에 곱해진 수 만큼 똑같이 곱해주기
	a = a * (lcd / b); 
	c = c * (lcd / d);
	// 3. 분자를 최소공배수만큼 바꿔주기
	b = b * (lcd / b);
	d = d * (lcd / d);
	// 4. 분자의 합 구하기
	sumOfNumerator = a + c;
	// 5. 분자와 분모의 최대공약수 구해서 분자와 분모 나누기
	gcd = getGcd(sumOfNumerator, b);
	cout << sumOfNumerator / gcd << ' ' << b / gcd;
	return 0;
}
ll getLcd(ll max, ll min) {
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
ll getGcd(ll max, ll min) {
	ll a = max, b = min, tmp;;
	while (b != 0)
	{
		tmp = a;
		a = b;
		b = tmp % b;
	}
	return a;
}