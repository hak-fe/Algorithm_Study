#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>

#define DEBUG 0
#define endl '\n'
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)
#define DIV 10000
#define MAX 10000

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int dz[2] = { 1, -1 };

int visited[10000]; //정정 방문 확인용
int parent[10000]; // ex) parent [2468] = 1234 : 2468이라는 수는 1234로 부터 만들어짐
char op[10000]; // ex) op[2468] = "D" : 2468이라는 수는 'D' 를 통하여 만들어짐

int D(string str);
int S(string str);
int L(string str);
int R(string str);
int bfs(string str, string des);
string getOpString(int firstNum, int num);

int main() {
	FASTIO;
	int t;
	cin >> t;
	while (t--) {
		string a, b;
		cin >> a >> b;
		
		//if (DEBUG) cout << D(a) << ' ' << S(a) << ' ' << L(a) << ' ' << R(a) << endl;
		
		int lastNum = bfs(a, b);
		string res = getOpString(stoi(a), lastNum);

		for (int i = res.size() - 1; i >= 0 ; i--)
			cout << res[i];
		cout << endl;
	}
}
int D(int n) {
	
	return 2 * n % DIV;
}
int S(int n) {
	if (n == 0)
		return 9999;
	return n - 1;
}
int L(int n) {
	return (n % 1000) * 10 + (n / 1000);
}
int R(int n) {
	return (n % 10) * 1000 + (n / 10);
}
int bfs(string str, string des) {

	for (int i = 0; i < MAX; i++)
	{
		visited[i] = 0;
		parent[i] = 0;
		op[i] = 0;
	}

	int res = stoi(des);
	char ops[4] = { 'D', 'S', 'L', 'R' };

	queue<int>q;
	q.push(stoi(str));
	visited[stoi(str)] = 1;
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			int n = q.front();
			q.pop();

			int nums[4] = { D(n) , S(n) , L(n) ,  R(n) };

			for (int j = 0; j < 4; j++)
			{
				if (!visited[nums[j]]) {
					q.push(nums[j]);
					visited[nums[j]] = 1;
					parent[nums[j]] = n;
					op[nums[j]] = ops[j];
					if(DEBUG) cout << nums[j] << endl;
					if (nums[j] == res)
						return res;
				}
			}
		}
	}
}
string getOpString(int firstNum, int num) {
	string res;
	while (!(num == firstNum)) {
		res.push_back(op[num]);
		num = parent[num];
	}
	return res;
}