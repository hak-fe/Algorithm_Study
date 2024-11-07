#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <deque>

#define MIN 2147483647;
#define MAX 0; 

using namespace std;
typedef unsigned long long int ll;
int arr[301] = {0, };
int p[301];
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
	}
	arr[1] = p[1];
	arr[2] = p[1] + p[2];
	arr[3] = max(arr[1] + p[3], p[2] + p[3]);
	for (int i = 4; i <= n; i++)
	{
		arr[i] = max(arr[i - 2] + p[i], arr[i - 3] + p[i - 1] + p[i]);
	}
	cout << arr[n];
}