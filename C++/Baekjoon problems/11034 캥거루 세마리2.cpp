#include <iostream>
using namespace std;


int main() {
	int kangaroo[3];
	int cnt = 0;
	while (cin >> kangaroo[0] >> kangaroo[1] >> kangaroo[2]) {
		cnt = 0;
		int max = 0;
		//A가 B, C 사이에 들어가는 경우
		for (int i = kangaroo[1] + 1; i < kangaroo[2]; i++)
		{
			cnt++;
		}
		max = cnt;
		cnt = 0;
		//C가 A, B 사이에 들어가는 경우
		for (int i = kangaroo[0] + 1; i < kangaroo[1]; i++)
		{
			cnt++;
		}
		if (cnt > max)
			max = cnt;
		cout << max << '\n';
	}
}