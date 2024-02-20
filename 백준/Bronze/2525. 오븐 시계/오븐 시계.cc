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

	int curHour, curMin, reqMin;
	cin >> curHour >> curMin >> reqMin;

	curHour += reqMin / 60;
	curMin += reqMin % 60;

	if (curMin >= 60) {
		curHour += curMin / 60;
		curMin = curMin % 60;
	}
	if (curHour >= 24) 
		curHour -= 24;
	
	cout << curHour << ' ' << curMin;
}