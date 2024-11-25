#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// 가장 크고 작은 x값, 가장 크고 작은 y값을 구해서 풀기
// n이 1이면 0출력

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, maxX, minX, maxY, minY, tempX, tempY;
	cin >> n;
	cin >> maxX >> maxY;
	minX = maxX;
	minY = maxY;
	if (n == 1) {
		cout << 0;
		return 0;
	}
	for (int i = 1; i < n; i++)
	{
		cin >> tempX >> tempY;
		if (tempX > maxX) maxX = tempX;
		if (tempX < minX) minX = tempX;
		if (tempY > maxY) maxY = tempY;
		if (tempY < minY) minY = tempY;
	}
	cout << (maxX - minX) * (maxY - minY);
	return 0;
}