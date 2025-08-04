#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>

#define DEBUG 0
#define endl '\n'
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)
#define DIV 10007
#define MAX 2001
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };


int main() {
	FASTIO;
	string str;
	cin >> str;
	if (str == "SONGDO")
		cout << "HIGHSCHOOL";
	else if (str == "CODE")
		cout << "MASTER";
	else if (str == "2023")
		cout << "0611";
	else
		cout << "CONTEST";
	return 0;
}