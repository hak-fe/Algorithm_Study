#include <iostream>
#include <string>
using namespace std;

class Printer {
protected:
	string model;
	string manufacturer;
	int printedCount;
	int availableCount;
public:
	Printer(string model, string manufacturer, int availableCount) {
		this->model = model;
		this->manufacturer = manufacturer;
		this->availableCount = availableCount;
	}
	virtual void print(int pages) = 0;
	virtual void show() = 0;
};

class InkPrinter : public Printer{
	int availableInk;
public:
	InkPrinter(string model, string manufacturer, int availableCount) : Printer(model, manufacturer, availableCount) {
		availableInk = 10;
	}
	void print(int pages) {
		if (availableCount - pages < 0) {
			cout << "용지가 부족하여 프린트 할 수 없습니다." << endl;
			return;
		}
		else if (availableInk - pages < 0) {
			cout << "잉크가 부족하여 프린트 할 수 없습니다." << endl;
			return;
		}
		else if (availableCount - pages < 0 || availableInk - pages < 0) {
			cout << "용지와 토너가 부족하여 프린트 할 수 없습니다." << endl;
			return;
		}
		else {
			cout << "프린트하였습니다." << endl;
			availableCount -= pages;
			availableInk -= pages;
		}
	}
	void show() {
		cout << "잉크젯 : " << model << " ," << manufacturer << " ," << "남은 종이 " << availableCount << "장 ," << "남은 잉크 " << availableInk << endl;
	}
};

class LaserPrinter : public Printer {
	int availableToner;
public:
	LaserPrinter(string model, string manufacturer, int availableCount) : Printer(model, manufacturer, availableCount) {
		availableToner = 20;
	}
	void print(int pages) {
		if (availableCount - pages < 0) {
			cout << "용지가 부족하여 프린트 할 수 없습니다." << endl;
		}
		else if (availableToner - pages < 0) {
			cout << "토너가 부족하여 프린트 할 수 없습니다." << endl;
		}
		else if (availableCount - pages < 0 || availableToner - pages < 0) {
			cout << "용지와 토너가 부족하여 프린트 할 수 없습니다." << endl;
		}
		else {
			cout << "프린트하였습니다." << endl;
			availableCount -= pages;
			availableToner -= pages;
		}
	}
	void show() {
		cout << "레이저 : " << model << " ," << manufacturer << " ," << "남은 종이 " << availableCount << "장 ," << "남은 토너 " << availableToner << endl;
	}
};

int main() {
	char running = 'y';
	int printNum, paperNum;
	InkPrinter IPrinter("Officejet V40", "HP", 5);
	LaserPrinter LPrinter("SCX-6x45", "삼성전자", 3);
	cout << "현재 작동중인 2 대의 프린터는 아래와 같다" << endl;
	IPrinter.show();
	LPrinter.show();
	cout << endl;
	while (true) {
		if (running == 'n')
			break;
		cout << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
		cin >> printNum >> paperNum;
		if (printNum == 1) {
			IPrinter.print(paperNum);
		}
		else if (printNum == 2) {
			LPrinter.print(paperNum);
		}
		else {
			cout << "프린터 선택이 잘못입력 되었습니다. 다시 입력해 주십시오." << endl;
		}
		IPrinter.show();
		LPrinter.show();
		while (true) {
			cout << "계속 프린트 하시겠습니까(y/n)>>";
			cin >> running;
			if (running != 'y' && running != 'n')
				cout << "y 또는 n을 입력해 주십시오." << endl;
			else {
				cout << endl;
				break;
			}
		}
	}
}
