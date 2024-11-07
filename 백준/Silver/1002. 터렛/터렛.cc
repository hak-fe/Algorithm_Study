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

	//d : 두 원의 중심 사이의 거리
	double x1, y1, r1, x2, y2, r2 , tc , d, temp; 
	cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
		temp = r1 > r2 ? r1 - r2 : r2 - r1; // 큰 r - 작은 r 해줘야 함
		if (d == 0 && r1 == r2) // 완전히 겹치는 경우
			cout << -1 << '\n';
		// 1. 한 점에서 만나는가?
		else if (d == r1 + r2 || temp == d) // 좌 : 외접 , 우 : 내접
			cout << 1 << '\n';
		// 2. 두 점에서 만나는가?
		else if (temp < d && r1 + r2 > d)
			cout << 2 << '\n';
		// 3. 만나지 않는가?
		else
			cout << 0 << '\n';
	}
}