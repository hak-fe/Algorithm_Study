#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

int ary[10000] = {};

int main()
{
	/*
	산술평균 : N개의 수들의 합을 N으로 나눈 값
	중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
	최빈값 : N개의 수들 중 가장 많이 나타나는 값
	범위 : N개의 수들 중 최댓값과 최솟값의 차이
	*/
	int n, temp, sum = 0, frequent = 0;
	vector<int>v; // 산술평균, 중앙값, 범위 구할 때 사용하는 벡터
	vector<int>v2; // 최빈값 구할 때 사용하는 벡터
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		sum += temp;
		v.push_back(temp);
		ary[temp + 4000]++;
	}
	sort(v.begin(), v.end());
	// 산술평균
	cout << floor((double)sum / n + 0.5) << '\n';
	//중앙값
	cout << v[n / 2] << '\n';
	//최빈값
	for (int i = 0; i <= v.back() + 4000; i++) {
		if (ary[i] > frequent)
			frequent = ary[i];
	}
	for (int i = 0; i <= v.back() + 4000; i++) {
		if (frequent == ary[i])
			v2.push_back(i - 4000);
	}
	sort(v2.begin(), v2.end());
	if (v2.size() == 1)
		cout << v2[0] << '\n';
	else
		cout << v2[1] << '\n';
	//범위
	cout << v.back() - v.front() << '\n';
}
