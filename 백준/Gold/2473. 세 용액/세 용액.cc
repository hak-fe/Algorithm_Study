#include<bits/stdc++.h>
using namespace std;
#define MAX 123456789123
#define DIV 1000000007
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL)
#define endl '\n'
typedef unsigned long long ull;
typedef long long ll;
int main() {
	ll minVal = MAX;
	int n;
	cin >> n;
	vector<ll> v(n);
	vector<int> res(3);
	for (int i = 0; i < 3; i++)
		res[i] = i;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n - 2; i++)
	{
		int front = i + 1, rear = n - 1;
		while (front < rear) {
			ll temp = v[i] + v[front] + v[rear];
			if (abs(temp) < abs(minVal)) {
				minVal = temp;
				res[0] = i, res[1] = front, res[2] = rear;
			}
			if (temp < 0) {
				front++;
			}
			else {
				rear--;
			}
		}
	}
	sort(res.begin(), res.end());
	for (int i = 0; i < 3; i++)
	{
		cout << v[res[i]] << ' ';
	}
	return 0;
}