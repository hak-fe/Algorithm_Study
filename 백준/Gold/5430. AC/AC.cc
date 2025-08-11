#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>

#define DEBUG 1
#define endl '\n'
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)
#define DIV 10007
#define MAX 2001
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int dz[2] = { 1, -1 };



int main() {
	FASTIO;
	int t;
	cin >> t;
	while (t--) {
		deque<int>dq;
		int n;
		string order, sequence, temp;
		cin >> order; //명령어 입력
		cin >> n; // 입력되는 정수의 갯수
		cin >> sequence; // 정수 수열

		// 수열 파싱
		for (int i = 1; i < sequence.length(); i++)
		{
			if ((sequence[i] == ',' || sequence[i] == ']') && !temp.empty()) {
				dq.push_back(stoi(temp));
				temp.clear();
			}
			else if (sequence[i] >= '0' && sequence[i] <= '9')
				temp.push_back(sequence[i]);
		}

		char dir = 'L';
		int error = 0;
		//명령어 실행
		for (int i = 0; i < order.length(); i++)
		{
			if (order[i] == 'R') {
				if (dir == 'L')
					dir = 'R';
				else
					dir = 'L';
			}
			else {
				if (dq.empty()) {
					error = 1;
					break;
				}
				if (dir == 'L') {
					dq.pop_front();
				}
				else {
					dq.pop_back();
				}
			}
		}
		if (error)
			cout << "error" << endl;
		else
		{
			if (!dq.empty()) {
				if (dir == 'L') {
					cout << '[' << dq[0];
					for (int i = 1; i < dq.size(); i++)
					{
						cout << ',' << dq[i];
					}
				}
				else
				{
					cout << '[' << dq[dq.size() - 1];
					for (int i = dq.size() - 2; i >= 0; i--)
					{
						cout << ',' << dq[i];
					}
				}
			}
			else
				cout << '[';
			cout << ']' << endl;
		}
	}
	return 0;
}