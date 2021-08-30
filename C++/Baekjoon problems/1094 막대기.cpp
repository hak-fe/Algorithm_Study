#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, min = 64;
	cin >> x;
	vector<int>v;
	v.push_back(64); //처음에는 64cm 막대 하나만 가지고 있다.
	while (true) {
		int sum = 0;
		for (int i = 0; i < v.size(); i++)
		{
			sum += v[i];
		}
		if (sum > x) { //이때, 합이 X보다 크다면, 아래와 같은 과정을 반복한다.
			sort(v.begin(), v.end());
			// 1. 가지고 있는 막대 중 길이가 가장 짧은 것을 절반으로 자른다.
			// 2. 만약, 위에서 자른 막대의 절반 중 하나를 버리고 남아있는 막대의 길이의 합이 X보다 크거나 같다면, 
			//	위에서 자른 막대의 절반 중 하나를 버린다.
			v[0] /= 2;
			if (sum - v[0] >= x)
				continue;
			else
				v.push_back(v[0]);
		}
		else
			break;
	}
	sort(v.begin(), v.end());
	int sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		sum += v[i];
		if (sum == x) {
			cout << i + 1;
			break;
		}
	}
}