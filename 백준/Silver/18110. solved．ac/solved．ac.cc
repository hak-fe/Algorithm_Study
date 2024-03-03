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
int level[31] = { 0, };
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	double numOfPeople, ans = 0;
	cin >> n;
	if (n == 0)
	{
		cout << 0;
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		level[temp]++;
	}
	numOfPeople = round(n * 0.15);
	for (int i = 1; i <= 30; i++)
	{
		if (numOfPeople == 0)
			break;
		while (numOfPeople != 0 && level[i] != 0) {
			level[i]--;
			numOfPeople--;
		}
	}
	numOfPeople = round(n * 0.15);
	for (int i = 30; i >= 1; i--)
	{
		if (numOfPeople == 0)
			break;
		while (numOfPeople != 0 && level[i] != 0) {
			level[i]--;
			numOfPeople--;
		}
	}
	numOfPeople = round(n * 0.15);
	for (int i = 1; i <= 30; i++)
	{
		ans += level[i] * i;
	}
	cout << round(ans / (n - round(2 * numOfPeople)));
}