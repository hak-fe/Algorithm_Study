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

void arrChange(int start, int end);
int arr[101];
int temparr[101] = { 0, };

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
		int start, end;
		cin >> start >> end;
		arrChange(start, end);
	}
	for (int i = 1; i <= n; i++)
	{
		cout << arr[i] << ' ';
	}
}
void arrChange(int start, int end) {
	int cnt = start;
	for (int i = end; i >= start; i--)
	{
		temparr[cnt] = arr[i];
		cnt++;
	}
	for (int i = start; i <= end; i++)
	{
		arr[i] = temparr[i];
	}
}