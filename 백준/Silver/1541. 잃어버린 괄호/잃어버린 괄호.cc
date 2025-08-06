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

vector<string>nums;
vector<int>negIndexes; // 음수의 인덱스를 찾아 저장

int main() {
	FASTIO;
	int negIdx = 0;
	ll res = 0, sum = 0;
	string str, temp;
	char lastSign = '+';
	cin >> str;

	//문자열 파싱 구현
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
			temp.push_back(str[i]);
		else {
			if (lastSign == '+') {
				nums.push_back(to_string(stoi(temp)));
			}
			else {
				nums.push_back("-" + to_string(stoi(temp)));
				negIndexes.push_back(negIdx);
			}
			lastSign = str[i];
			temp.clear();
			negIdx++;
		}
	}
	if (lastSign == '+')
		nums.push_back(to_string(stoi(temp)));
	else {
		nums.push_back("-" + to_string(stoi(temp)));
		negIndexes.push_back(negIdx);
	}

	//if (DEBUG)
	//	for (int i = 0; i < nums.size(); i++)
	//		cout << nums[i] << endl;

	//if (DEBUG)
	//	for (int i = 0; i < negIndexes.size(); i++)
	//		cout << negIndexes[i] << endl;

	//최솟값 구하기
	if (negIndexes.size() == 0) {
		for (int i = 0; i < nums.size(); i++)
			res += stoi(nums[i]);
	}
	else {
		for (int i = 0; i < negIndexes[0]; i++)
			res += stoi(nums[i]);

		for (int i = 0; i < negIndexes.size() - 1; i++)
		{
			for (int s = negIndexes[i] + 1; s < negIndexes[i + 1]; s++)
			{
				sum += stoi(nums[s]);
			}
			sum += -stoi(nums[negIndexes[i]]);
			res += -sum;
			if (DEBUG) cout << -sum << "더하기" << endl;
			sum = 0;
		}
		for (int i = negIndexes[negIndexes.size() - 1] + 1; i < nums.size(); i++) {
			sum += stoi(nums[i]);
		}
		sum += -stoi(nums[negIndexes[negIndexes.size() - 1]]);
		res += -sum;
		if (DEBUG) cout << -sum << "더하기" << endl;
	}
	cout << res;
	return 0;
}