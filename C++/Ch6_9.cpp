#include <iostream>
using namespace std;

class Board {
	static string writing[];
	static int size;
public:
	static void add(string t);
	static void print();
};
int Board::size = 0;
string Board::writing[100];

void Board::add(string t) {
	writing[size] = t;
	size++;
}

void Board::print() {
	cout << "*************** �Խ��� �Դϴ� ***************" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << i << ": " << writing[i] << endl;
	}
}

int main() {
	Board::add("�߰����� ���� ���� ���� �����Դϴ�.");
	Board::add("�ڵ� ����� ���� �̿��� �ּ���.");
	Board::print();
	Board::add("���Ҹ� �л��� ������ȸ �Ի��Ͽ����ϴ�. �������ּ���");
	Board::print();
}