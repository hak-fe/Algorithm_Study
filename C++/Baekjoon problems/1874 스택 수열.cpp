#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <stack>
using namespace std;

int main() {

	stack<int>s;
	vector<char>result;
	int cnt = 1; // 1에서 n까지 증가할 수
	int n; // 반복 횟수
	cin >> n;

	while (n--) {
	
		int x; // 수열을 입력받을 변수
		cin >> x;

		while (cnt <= x) // 카운트가 수열의 수 이하면 
		{
			s.push(cnt); // cnt를 스택에 넣음
			cnt += 1;// 수 1 증가
			result.push_back('+'); // pushback 했으믈 result 벡터에 + 문자 넣음
		}
		if (s.top() == x) 
		// 위 반복문에서 cnt를 s에 계속 넣다가 탈출되면 s의 윗부분과 x 를 비교함.
		// 같다면, s에서 지우고 result에 - 입력
		{
			s.pop();
			result.push_back('-');
		}
		else
		// 다르면 주어진 수열과 다르므로 no를 출력하고 프로그램 종료
		{
			cout << "NO";
			return 0;
		}
	}
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << '\n';
	}
}