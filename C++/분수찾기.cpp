#include <iostream>
using namespace std;

int main()
{
	int x; // input

	cin >> x;

	int line; //몇 번째 줄?

	for (line = 1; x > 0; line++) // ***반복 조건의 바로 직전의 값을 적용시킨다
	{
		x = x - line;
	} // x에서 line을 계속 빼주는데, x > 0이라는 반복 조건을 성립하지 않을 때의 line이 곧 줄의 수다.
	//ex) x == 2일 때, x = - 1 일때 종료, line은 2
	if (line % 2 == 1)
	{
		cout << line + x - 1 << "/" << 1 - x << endl;
	}
	else if (line % 2 == 0)
	{
		cout << 1 - x << "/" << line + x - 1 << endl;
	}
}