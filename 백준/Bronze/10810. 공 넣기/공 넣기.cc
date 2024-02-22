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

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int arr[101] = { 0, };
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int start, end, ballnum;
		cin >> start >> end >> ballnum;
		for (int j = start; j <= end; j++)
		{
			arr[j] = ballnum;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << arr[i] <<' ';
	}
}