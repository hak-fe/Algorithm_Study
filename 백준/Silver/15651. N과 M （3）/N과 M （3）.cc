#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
//숫자사용 확인배열을 선언하여 어떤 숫자가 사용되었는지 표시하기
// 일단 해보자
int checkNum[9];
vector<int>v;
//bool checkVector(vector<int> v);
void function(int end, int curLength, int length);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	function(n, 0, m);
	return 0;
}
/*
bool checkVector(vector<int> v) {
	for (int i = 0; i < v.size() -1; i++)
	{
		if (v[i] > v[i + 1])
			return false;
	}
	return true;
}
*/
void function(int end, int curLength, int length) {
	// 최종 길이에 도달하면 저장한 값들을 전부 털어줌.
	//
	if (curLength == length)
	{
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << ' ';
		cout << '\n';
		return;
	}
	else
	{
		for (int i = 1; i <= end; i++) {
			v.push_back(i);
			function(end, curLength + 1, length); // 찾을 만큼 다 찾고
			v.pop_back();
		}
	}
}