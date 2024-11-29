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

vector<int>v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, temp, distance, cnt = 0, gcd;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	distance = getGcd(max(v[1] - v[0], v[2] - v[1]),
		min(v[1] - v[0], v[2] - v[1]));

	for (int i = 2; i < n - 1; i++)
	{
		if ((gcd = getGcd(max(v[i + 1] - v[i], distance),
			min(v[i + 1] - v[i], distance))) < distance)
			distance = gcd;
	}
	for (int i = 0; i < n - 1; i++)
	{
		if ((v[i + 1] - v[i]) % distance == 1)
			cnt += (v[i + 1] - v[i]) / distance;
		else
			cnt += (v[i + 1] - v[i]) / distance - 1;
	}
	cout << cnt;
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