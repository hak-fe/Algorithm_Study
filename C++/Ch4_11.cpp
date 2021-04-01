#include <iostream>
using namespace std;

class Container {
	int size;
public:
	Container() { size = 10; }
	void fill() { size = 10; };
	void consume() { --size; };
	int getsize() { return size; };
};


class CoffeeVendingMachine {
	int size = 10;
	Container tong[3];
	void fill();
	void selectEspresso();
	void selectAmericano();
	void selectSugarCoffee();
	void show();
public:
	void run();
	int empty = 0;
};
void  CoffeeVendingMachine::fill() {
	for (int i = 0; i < 3; i++)
	{
		tong[i].fill();
	}
	cout << "Ŀ�� " << tong[0].getsize() << " �� " << tong[1].getsize() << " ���� " << tong[2].getsize() << endl;
	empty = 0;
}

void CoffeeVendingMachine::selectEspresso() {
	tong[0].consume();
	tong[1].consume();
	for (int i = 0; i < 2; i++)
	{
		if (tong[i].getsize() < 0)
			empty = 1;
	}
	if (empty == 0)
		cout << "���������� �弼�� " << endl;
	else
		cout << "���ᰡ �����մϴ�." << endl;
	empty = 0;
};
void  CoffeeVendingMachine::selectAmericano() {
	tong[0].consume();
	tong[1].consume();
	tong[1].consume();

	for (int i = 0; i < 2; i++)
	{
		if (tong[i].getsize() < 0)
			empty = 1;
	}
	if (empty == 0)
		cout << "�Ƹ޸�ī�� �弼�� " << endl;
	else
		cout << "���ᰡ �����մϴ�." << endl;
	empty = 0;
};
void  CoffeeVendingMachine::selectSugarCoffee() {
	tong[0].consume();
	tong[1].consume();
	tong[1].consume();
	tong[2].consume();

	for (int i = 0; i < 3; i++)
	{
		if (tong[i].getsize() < 0)
			empty = 1;
	}
	if (empty == 0)
		cout << "����Ŀ�� �弼�� " << endl;
	else
		cout << "���ᰡ �����մϴ�." << endl;
	empty = 0;

};
void  CoffeeVendingMachine::show() {
	cout << "Ŀ�� " << tong[0].getsize() << " �� " << tong[1].getsize() << " ���� " << tong[2].getsize() << endl;

};
void  CoffeeVendingMachine::run() {

	int choice = 0;
	cout << "***** Ŀ�� ���Ǳ⸦ �۵��մϴ�. *****" << endl;
	while (true) {
		cout << "�޴��� �����ּ���(1:����������, 2:�Ƹ޸�ī��, 3:����Ŀ��, 4:�ܷ�����, 5:ä���)>> ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			selectEspresso();
			break;
		case 2:
			selectAmericano();
			break;
		case 3:
			selectSugarCoffee();
			break;
		case 4:
			show();
			break;
		case 5:
			fill();
			break;
		default:
			cout << "�Է��� �߸��Ǿ����ϴ�." << endl;
			break;
		}
	}
};

int main(void) {
	CoffeeVendingMachine p;
	p.run();
}