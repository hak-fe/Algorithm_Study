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
			cout << "������ �����Ͽ� ����Ʈ �� �� �����ϴ�." << endl;
			return;
		}
		else if (availableInk - pages < 0) {
			cout << "��ũ�� �����Ͽ� ����Ʈ �� �� �����ϴ�." << endl;
			return;
		}
		else if (availableCount - pages < 0 || availableInk - pages < 0) {
			cout << "������ ��ʰ� �����Ͽ� ����Ʈ �� �� �����ϴ�." << endl;
			return;
		}
		else {
			cout << "����Ʈ�Ͽ����ϴ�." << endl;
			availableCount -= pages;
			availableInk -= pages;
		}
	}
	void show() {
		cout << "��ũ�� : " << model << " ," << manufacturer << " ," << "���� ���� " << availableCount << "�� ," << "���� ��ũ " << availableInk << endl;
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
			cout << "������ �����Ͽ� ����Ʈ �� �� �����ϴ�." << endl;
		}
		else if (availableToner - pages < 0) {
			cout << "��ʰ� �����Ͽ� ����Ʈ �� �� �����ϴ�." << endl;
		}
		else if (availableCount - pages < 0 || availableToner - pages < 0) {
			cout << "������ ��ʰ� �����Ͽ� ����Ʈ �� �� �����ϴ�." << endl;
		}
		else {
			cout << "����Ʈ�Ͽ����ϴ�." << endl;
			availableCount -= pages;
			availableToner -= pages;
		}
	}
	void show() {
		cout << "������ : " << model << " ," << manufacturer << " ," << "���� ���� " << availableCount << "�� ," << "���� ��� " << availableToner << endl;
	}
};

int main() {
	char running = 'y';
	int printNum, paperNum;
	InkPrinter IPrinter("Officejet V40", "HP", 5);
	LaserPrinter LPrinter("SCX-6x45", "�Ｚ����", 3);
	cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����" << endl;
	IPrinter.show();
	LPrinter.show();
	cout << endl;
	while (true) {
		if (running == 'n')
			break;
		cout << "������(1:��ũ��, 2:������)�� �ż� �Է�>>";
		cin >> printNum >> paperNum;
		if (printNum == 1) {
			IPrinter.print(paperNum);
		}
		else if (printNum == 2) {
			LPrinter.print(paperNum);
		}
		else {
			cout << "������ ������ �߸��Է� �Ǿ����ϴ�. �ٽ� �Է��� �ֽʽÿ�." << endl;
		}
		IPrinter.show();
		LPrinter.show();
		while (true) {
			cout << "��� ����Ʈ �Ͻðڽ��ϱ�(y/n)>>";
			cin >> running;
			if (running != 'y' && running != 'n')
				cout << "y �Ǵ� n�� �Է��� �ֽʽÿ�." << endl;
			else {
				cout << endl;
				break;
			}
		}
	}
}