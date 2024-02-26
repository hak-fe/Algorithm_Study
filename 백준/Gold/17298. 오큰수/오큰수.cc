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
	stack<int>st;
	int n, num;

	cin >> n;

	int* ary = new int[n]; // 수열을 담을 배열 생성
	int* result = new int[n]; // 결과 출력 배열 생성

	for (int i = 0; i < n; i++)
	{
		cin >> ary[i]; // 수열 입력
	}

	for (int i = n - 1; i >= 0; i--)
	{
		while (!st.empty() && st.top() <= ary[i])
			st.pop();

		if (st.empty())
			result[i] = -1;
		else
			result[i] = st.top();

		st.push(ary[i]);
	}
	for (int i = 0; i < n; i++)
	{
		cout << result[i] << ' ';
	}
	delete[] ary;
	delete[] result;
}