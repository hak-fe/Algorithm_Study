#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 10000
#define DIV 1000000007
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL)
#define endl '\n'

typedef unsigned long long ull;
typedef long long ll;
vector<ll>coordX;
vector<ll>coordY;
ll getFirst(int n) {
	ll sum = 0;
	for (int x = 0, y = 1; x < n && y <= n; x++, y++)
	{
		sum += coordX[x] * coordY[y];
	}
//	cout << "First : " << sum << endl;
	return sum;
}
ll getsecond(int n) {
	ll sum = 0;
	for (int x = 1, y = 0; x <= n && y < n; x++, y++)
	{
		sum += coordX[x] * coordY[y];
	}
//	cout << "Second : " << sum << endl;
	return sum;
}
int main() {
	FASTIO;
	int n;
	double res;
	cin >> n;
	coordX.assign(n, 0);
	coordY.assign(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> coordX[i] >> coordY[i];
	}
	coordX.push_back(coordX[0]);
	coordY.push_back(coordY[0]);

	res = abs(getFirst(n) - getsecond(n)) / 2.0;
	printf("%.1lf", res);
	return 0;
}