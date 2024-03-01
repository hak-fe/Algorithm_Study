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
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		cout << (char)(str[i] - 32);
	}
}