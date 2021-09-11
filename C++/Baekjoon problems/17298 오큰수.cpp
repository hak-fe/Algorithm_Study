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
	// 중요한 점 - 여기서 스택은 수열을 거꾸로 탐색하며 오큰수를 찾아주는 역할을 함.
	for (int i = n - 1; i >= 0; i--)
	{
		while (!st.empty() && st.top() <= ary[i])
			// 스택 안에 수가 존재하고, 스택의 윗부분이 수열 이하일 때,
			st.pop(); // 이 수는 오큰수가 될 수 없으므로 스택을 팝시킴.

		if (st.empty()) 
			// 스택이 비어있으면 오큰수가 없다는 뜻이므로
			// 동일한 인덱스의 결과 배열에 -1을 넣어줌
			result[i] = -1;
		else
			// else일 경우는 해당 스택의 윗부분이 ary[i]의 오큰수라는 뜻이므로
			// 동일한 인덱스를 가지는 결과 배열에 현재 스택의 top(오큰수)를 넣어줌
			result[i] = st.top();

		st.push(ary[i]); // 다음 오큰수를 찾기 위해 ary[i] 값을 스택에 푸쉬
	}
	for (int i = 0; i < n; i++)
	{
		cout << result[i] << ' ';
	}
	delete[] ary;
	delete[] result;
}