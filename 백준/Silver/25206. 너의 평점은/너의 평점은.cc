#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <deque>
#include <utility>

#define MIN 0
#define MAX 10000000
using namespace std;
typedef unsigned long long int ll;

double returnMyGrade(string str);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string subject, mygrade;
	double totalscore = 0, totalmyscore = 0, score;

	for (int i = 0; i < 20; i++)
	{
		cin >> subject >> score >> mygrade;
		if (mygrade != "P")
		{
			totalscore += score;
			totalmyscore += score * returnMyGrade(mygrade);
		}
	}
	cout << totalmyscore / totalscore;
}

double returnMyGrade(string str) {
	if (str == "A+")
		return 4.5;
	else if (str == "A0")
		return 4.0;
	else if (str == "B+")
		return 3.5;
	else if (str == "B0")
		return 3.0;
	else if (str == "C+")
		return 2.5;
	else if (str == "C0")
		return 2.0;
	else if (str == "D+")
		return 1.5;
	else if (str == "D0")
		return 1.0;
	else if (str == "F")
		return 0;
}