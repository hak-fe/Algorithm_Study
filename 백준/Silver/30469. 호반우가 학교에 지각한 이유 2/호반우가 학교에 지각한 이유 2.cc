#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include<algorithm>

#define DEBUG 1
#define endl '\n'
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)

using namespace std;
typedef long long int ll;

void func(int a, int b, int n);

int main() {
	FASTIO;
	int a, b, n;
	cin >> a >> b >> n;
	if ((b / 10) % 2 == 0 || b / 10 == 5) {
		cout << -1;
	}
	else {
		func(a, b, n);
	}
	return 0;
}

void func(int a, int b, int n) {
	string str;
	if (a % 10 == 1 || a % 10 == 3 || a % 10 == 7) {
		n = n - 4;
		str += to_string(a);
		for (int i = 0; i < n; i++)
		{
			str.push_back('1');
		}
		str += to_string(b);
	}
	else {
		n = n - 5;
		str += to_string(a);
		str.push_back('7');
		for (int i = 0; i < n; i++)
		{
			str.push_back('1');
		}
		str += to_string(b);
	}
	cout << str;
}