#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <deque>

#define MIN 2147483647;
#define MAX 0; 

using namespace std;
typedef unsigned long long int ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int sixNineCnt = 0;
	int elseCnt = 0;
	int numCnt[10] = {0, };
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++) 
		numCnt[str[i] - '0']++;
	sixNineCnt = (numCnt[6] + numCnt[9]) % 2 == 0 ? (numCnt[6] + numCnt[9]) / 2 :
		(numCnt[6] + numCnt[9]) / 2 + 1;
	elseCnt = numCnt[0];
	for (int i = 1; i < 10; i++)
		if (!(i == 6) && !(i == 9)) 
			elseCnt = max(elseCnt, numCnt[i]);
	cout << max(sixNineCnt, elseCnt) << '\n';
}