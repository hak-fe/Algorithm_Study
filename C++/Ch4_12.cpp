#include <iostream>
using namespace std;

class Circle{
	int radius;// ���� ������ ��
	string name; // ���� �̸�
public:
	void setCircle(string name, int radius) { this->name = name; this->radius = radius; }; // �̸��� ������ ����
	double getArea() { return radius * radius * 3.14; };
	string getName() { return name; };
};

class CircleManager{
	Circle* p; // Circle �迭�� ���� ������
	int size; // �迭�� ũ��
public:
	CircleManager(int size); // size ũ���� �迭�� ���� ����. ����ڷκ��� �Է� �Ϸ�
	~CircleManager();
	void searchByName();// ����ڷκ��� ���� �̸��� �Է¹޾� ���� ���
	void searchByArea(); // ����ڷκ��� ������ �Է¹޾� �������� ū ���� �̸� ���
	
};

CircleManager::CircleManager(int size)
{
	string Name;
	int radius;
	this->size = size;
	p = new Circle[size];
	for (int i = 0; i < size; i++)
	{
		cout << "�� " << i + 1 << "�� �̸��� ������ >> ";
		cin >> Name >> radius;
		p[i].setCircle(Name, radius);
	}
}

CircleManager::~CircleManager()
{
}

void CircleManager::searchByName() {
	string inputName;
	cout << "�˻��ϰ��� �ϴ� ���� �̸� >> ";
	cin >> inputName;
	for (int i = 0; i < size; i++)
	{
		if (inputName == p[i].getName()) {
			cout << p[i].getName() << "�� ������ " << p[i].getArea() << endl;
		}
	}
}

void CircleManager::searchByArea() {
	int Area;
	cout << "�ּ� ������ ������ �Է��ϼ��� >> ";
	cin >> Area;
	cout << Area << "���� ū ���� �˻��մϴ�." << endl;
	for (int i = 0; i < size; i++)
	{
		if (p[i].getArea() > Area) {
			cout << p[i].getName() << "�� ������ " << p[i].getArea() << ", ";
		}
	}
}

int main() {
	int num, radius;
	string Name;
	cout << "���� ���� >> ";
	cin >> num;
	CircleManager p(num);
	p.searchByName();
	p.searchByArea();
}