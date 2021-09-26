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
typedef unsigned long long int ll;

int Bsearch(ll ary[], int size, ll findingNum)  // 이진탐색 소스
{
	int start = 0; // 시작 인덱스
	int end = size - 1; // 끝 인덱스
	int mid = 0; // 중간 인덱스
	while (start <= end)
	{
		/*if (ary[start] < findingNum && ary[end] < findingNum)
			return 0;*/
		mid = (start + end) / 2; // 찾고 있는 부분의 중간 인덱스를 넣어줌 
		if (ary[mid] == findingNum) // 찾고자 하는 수를 발견하면 1 리턴
			return 1;
		else // 원하는 수를 발견 못했다면?
		{
			if (ary[mid] < findingNum) // 현재 찾은 수가 찾고자 하는 수 보다 작을 경우
				start = mid + 1;
			// start 인덱스를 mid + 1로 바꾼다. -> 큰 쪽으로 민다.
			//ex) 1,2,3,4,5,6,7 이 들어있고, 5를 찾아야 하는데, 4를 찾았다면?
			// 1부터 4 까지는 안봐도 되니까, start를 5부터 시작하도록 바꾼다.
			else if (ary[mid] > findingNum) // 현재 찾은 수가 찾고자 하는 수 보다 클 경우
				end = mid - 1;
			//위에서 한 것과 반대로, 이번에는 end를 앞으로 당긴다.
			//ex) 1,2,3,4,5,6,7 이 들어있고, 2를 찾아야 하는데, 4를 찾았다면?
			// 4부터 7 까지는 안봐도 되니까, end를 3부터 시작하도록 바꾼다.
		}
	}
	return 0; // while을 돌아도 못 찾는다면 0출력
}

int main()
{
	int n, m;
	cin >> n;
	ll* firstAry = new ll[n];
	for (int i = 0; i < n; i++)
		cin >> firstAry[i];
	sort(firstAry, firstAry + n);
	cin >> m;
	ll* secondAry = new ll[m];
	for (int i = 0; i < m; i++)
		cin >> secondAry[i];

	for (int i = 0; i < m; i++)
	{
		cout << Bsearch(firstAry, n, secondAry[i]) << '\n';
	}
}