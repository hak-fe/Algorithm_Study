#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <deque>
#include <utility>

#define MIN 0
#define MAX 10000000

using namespace std;
typedef unsigned long long int ll;

int arr[101];
void arrChange(int fir, int sec);
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		arr[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		int first, second;
		cin >> first >> second;
		arrChange(first, second);
	}
	for (int i = 1; i <= n; i++)
	{
		cout << arr[i] << ' ';
	}
}
void arrChange(int fir, int sec) {
	int temp;
	temp = arr[fir];
	arr[fir] = arr[sec];
	arr[sec] = temp;
}