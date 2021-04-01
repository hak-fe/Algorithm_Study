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
	cout << "커피 " << tong[0].getsize() << " 물 " << tong[1].getsize() << " 설탕 " << tong[2].getsize() << endl;
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
		cout << "에스프레소 드세요 " << endl;
	else
		cout << "원료가 부족합니다." << endl;
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
		cout << "아메리카노 드세요 " << endl;
	else
		cout << "원료가 부족합니다." << endl;
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
		cout << "설탕커피 드세요 " << endl;
	else
		cout << "원료가 부족합니다." << endl;
	empty = 0;

};
void  CoffeeVendingMachine::show() {
	cout << "커피 " << tong[0].getsize() << " 물 " << tong[1].getsize() << " 설탕 " << tong[2].getsize() << endl;

};
void  CoffeeVendingMachine::run() {

	int choice = 0;
	cout << "***** 커피 자판기를 작동합니다. *****" << endl;
	while (true) {
		cout << "메뉴를 눌러주세요(1:에스프레소, 2:아메리카노, 3:설탕커피, 4:잔량보기, 5:채우기)>> ";
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
			cout << "입력이 잘못되었습니다." << endl;
			break;
		}
	}
};

int main(void) {
	CoffeeVendingMachine p;
	p.run();
}