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

	int crain,box; // 크레인 수, box 수
	vector<int>crainLimit;// 크레인 무게 제한
	vector<int>boxWeight;// 박스 무게

	cin >> crain;
	for (int i = 0; i < crain; i++)
	{
		int temp;
		cin >> temp;
		crainLimit.push_back(temp);
	}
	cin >> box;
	for (int i = 0; i < box; i++)
	{
		int temp;
		cin >> temp;
		boxWeight.push_back(temp);
	}
	sort(crainLimit.begin(), crainLimit.end(), greater<>());
	sort(boxWeight.begin(), boxWeight.end(), greater<>());
	// 크레인 무게 제한보다 큰 박스가 존재한다면 -1 출력
	bool overlimit = false;
	for (int i = 0; i < box; i++)
	{
		if (boxWeight[i] > crainLimit[0]) {
			overlimit = true;
			break;
		}
	}
	if (overlimit)
		cout << -1;
	else {
	
	
	}
}