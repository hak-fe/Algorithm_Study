#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long int ll;
/*
while - 대기열과 왼쪽 공간이 전부 빌 때 까지
	if - 대기열과 왼쪽공간 둘 다 학생이 존재하는 경우
		1. 왼쪽공간 확인하기
			1-1 order와 번호표가 같으면 보내기, order++
			1-2 order와 번호표가 다르면 동작x
		2. 대기열 확인하기
			2-1 order와 번호표가 같으면 보내기, order++
			2-2 order와 번호표가 다르면 한 명을 왼쪽 공간으로 보내기

	 else if - 대기열만 존재하는 경우
		1. order와 번호표가 같은 경우
			보내고 order++
		2. 다른 경우 왼쪽 공간으로 한 명 보내기
 
	 else - 왼쪽공간만 존재하는 경우
		1. order와 번호표가 같은경우
			보내고 order++
		2. order와 번호표가 다른 경우
			Sad 출력 후 프로그램 종료
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, tmp, order = 1;
	cin >> n;
	queue<int>q;
	stack<int>st;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		q.push(tmp);
	}
	while (!q.empty() || !st.empty())
	{
		if (!q.empty() && !st.empty()) {
			if (st.top() == order) {
				order++;
				st.pop();
			}
			else if (q.front() == order) {
				order++;
				q.pop();
			}
			else {
				st.push(q.front());
				q.pop();
			}
		}
		else if (!q.empty()) {
			if (order == q.front()) {
				q.pop();
				order++;
			}
			else{
				st.push(q.front());
				q.pop();
			}
		}
		else {
			if (order == st.top()) {
				st.pop();
				order++;
			}
			else {
				cout << "Sad";
				return 0;
			}
		}
	}
	cout << "Nice";
	return 0;
}