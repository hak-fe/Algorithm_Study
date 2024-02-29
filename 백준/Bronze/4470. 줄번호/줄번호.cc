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
	
	int n;
	vector<string>v;
	string str;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		getline(cin, str);
		v.push_back(str);
	}
	for (int i = 0; i < v.size(); i++)
	{
		cout << i + 1 << ". " << v[i] <<'\n';
	}
}