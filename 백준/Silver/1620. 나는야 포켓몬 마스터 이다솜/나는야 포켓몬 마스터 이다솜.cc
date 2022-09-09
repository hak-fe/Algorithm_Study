#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <deque>
#include <map>

#define MIN 2147483647;
#define MAX 0; 

using namespace std;
typedef unsigned long long int ll; // 음수 포함일 때는 unsinged 꼭 해제
map<string, int> nameAndNum;
map<int, string> numAndName;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string str;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> str;
		nameAndNum.insert(make_pair(str, i));
		numAndName.insert(make_pair(i, str));
	}
	for (int i = 0; i < m; i++)
	{
		cin >> str;
		if (nameAndNum.find(str) != nameAndNum.end())
			cout << nameAndNum[str] << '\n';
		else
			cout << numAndName[stoi(str)] << '\n';
	}
}