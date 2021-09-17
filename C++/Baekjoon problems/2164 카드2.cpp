#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
int main()
{
	deque<int>d;
	int n;
	cin >> n;
	for (int i = n; i >= 1; i--)
	{
		d.push_back(i);
	}
	while (d.size() != 1) {
		// 1. 제일 위에 있는 카드를 바닥에 버린다.
		d.pop_back(); 
		// 2. 제일 위에 있는 카드를 제일 아래에 있는 카드 밑으로 옮긴다.
		d.push_front(d.back());
		d.pop_back();
	}
	cout << d.front();
}