#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	void setRadius(int radius);
	double getArea();
};

void Circle::setRadius(int radius) {
	this->radius = radius;
}

double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main(void) {
	int r, cnt = 0, numOfCircle;

	cout << "���� ���� >> ";
	cin >> numOfCircle;

	Circle* p = new Circle[numOfCircle];

	for (int i = 0; i < numOfCircle; i++)
	{
		cout << "�� " << i + 1 << "�� ������ >> ";
		cin >> r;
		p[i].setRadius(r);
		if (p[i].getArea() > 100)
			cnt++;
	}
	cout << "������ 100���� ū ���� " << cnt << "�� �Դϴ�." << endl;
	delete []p;
}