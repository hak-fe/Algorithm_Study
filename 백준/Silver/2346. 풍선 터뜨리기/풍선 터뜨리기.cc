#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;
vector<int>func(int n);
int balloons[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector <int> result;
	for (int i = 1; i <= n; i++)
		cin >> balloons[i];
	
	result = func(n);
	
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << ' ';
	
	return 0;
}
vector<int> func(int n) {
	vector<int>v;
	int tmp = balloons[1], index = 1; // 첫 시작은 1번 풍선
	v.push_back(1); // 1번을 터뜨림
	balloons[1] = 0; 
	while (v.size() != n) {
		if (tmp > 0) { // 우측으로 가기
			if (index != n) { // 끝 지점인지 확인
				index++;
				if (balloons[index] != 0) {
					// 안 터진 풍선인 경우만 이동 횟수 감소
					tmp--;
				}
				else
					continue;
			}
			else { 
				// 끝지점 일 때
				index = 1; // 맨 왼쪽으로 이동
				if (balloons[index] != 0) {
					// 안 터진 풍선인 경우만 이동 횟수 감소
					tmp--;
				}
				else
					continue;
			}
		}
		else if (tmp < 0) {
			if (index != 1) { // 가장 왼쪽이 아니다.
				index--;
				if (balloons[index] != 0) {
					// 안 터진 풍선인 경우만 이동 횟수 증가 (음수라서)
					tmp++;
				}
				else
					continue;
			}
			else {
				// 가장 왼쪽이다.
				index = n; // 맨 오른쪽으로 이동
				if (balloons[index] != 0) {
					// 안 터진 풍선인 경우만 이동 횟수 증가 (음수라서)
					tmp++;
				}
				else
					continue;
			}
		}
		else { // 풍선을 터뜨려야 하는 위치 tmp == 0
			tmp = balloons[index];
			balloons[index] = 0;
			v.push_back(index);
		}
	}
	return v;
}