#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include<algorithm>
#define DEBUG 1
#define endl '\n'
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)

using namespace std;
typedef long long int ll;

vector<int>positive;
vector<int>negative;

int main() {
	FASTIO;
	int n, temp, result1, result2;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		if (temp >= 1)
			positive.push_back(temp);
		else
			negative.push_back(temp);
	}

	sort(positive.begin(), positive.end());
	sort(negative.begin(), negative.end(), greater<>());

	if (negative.size() == 0) {
		for (int i = 0; i < 2; i++)
			cout << positive[i] << ' ';

	}
	else if (positive.size() == 0) {
		for (int i = 1; i >= 0; i--)
			cout << negative[i] << ' ';
	}
	else {
		int negPointer = 0, posPointer = 0, temp, posSize = positive.size(), negSize = negative.size();
		temp = positive[posPointer] + negative[negPointer];
		result1 = negative[negPointer], result2 = positive[posPointer];
		if (abs(positive[posPointer]) > abs(negative[negPointer]))
			negPointer++;
		else if (abs(positive[posPointer]) < abs(negative[negPointer]))
			posPointer++;
		else {
			cout << result1 << ' ' << result2;
			return 0;
		}
		while (negPointer < negSize && posPointer < posSize) { // 양수, 음수 섞어서 계산
			if (abs(positive[posPointer] + negative[negPointer]) < abs(temp)) {
				temp = positive[posPointer] + negative[negPointer];
				result1 = negative[negPointer], result2 = positive[posPointer];
			}
			if (abs(positive[posPointer]) > abs(negative[negPointer]))
				negPointer++;
			else if (abs(positive[posPointer]) < abs(negative[negPointer]))
				posPointer++;
			else {
				cout << result1 << ' ' << result2;
				return 0;
			}
		}
		//예외처리
		//양수만 계산
		if (posSize > 1) {
			if (abs(positive[0] + positive[1]) < abs(temp))
				result1 = positive[0], result2 = positive[1];
		}
		//음수만 계산
		if (negSize > 1) {
			if (abs(negative[0] + negative[1]) < abs(temp))
				result1 = negative[1], result2 = negative[0];
		}
		cout << result1 << ' ' << result2;
	}

	return 0;
}