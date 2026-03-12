#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 2100000000
#define DIV 1000000007
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL)
#define endl '\n'

typedef unsigned long long ull;
typedef long long ll;
vector<int>v;

void func(int size, int currentNum, int left, int right, int* first, int* second, ll *sum) {

	while (left <= right) {
		int mid = (left + right) / 2;
		if (currentNum + v[mid] == 0 || abs(currentNum + v[mid]) < abs(*sum)) {
			*first = currentNum;
			*second = v[mid];
			//cout << *first << ' ' << *second << endl;
			*sum = currentNum + v[mid];
		}
		if (currentNum < 0) {
			if (abs(v[mid]) < abs(currentNum))
				left = mid + 1;
			else
				right = mid - 1;
		}
		else { // 12 13 14 
			right = mid - 1;
		}
	}
	return;
}

int main() {
	FASTIO;
	ll sum = MAX;
	int n, first, second;
	cin >> n;
	v.assign(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	for (int i = 0; i < n - 1; i++)
	{
		func(n, v[i], i + 1, n - 1, &first, &second, &sum);
	}
	cout << first << ' ' << second;
	return 0;
}