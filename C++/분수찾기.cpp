#include <iostream>
using namespace std;

int main()
{
	int x; // input

	cin >> x;

	int line; //�� ��° ��?

	for (line = 1; x > 0; line++) // ***�ݺ� ������ �ٷ� ������ ���� �����Ų��
	{
		x = x - line;
	} // x���� line�� ��� ���ִµ�, x > 0�̶�� �ݺ� ������ �������� ���� ���� line�� �� ���� ����.
	//ex) x == 2�� ��, x = - 1 �϶� ����, line�� 2
	if (line % 2 == 1)
	{
		cout << line + x - 1 << "/" << 1 - x << endl;
	}
	else if (line % 2 == 0)
	{
		cout << 1 - x << "/" << line + x - 1 << endl;
	}
}