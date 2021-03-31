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

	cout << "원의 개수 >> ";
	cin >> numOfCircle;

	Circle* p = new Circle[numOfCircle];

	for (int i = 0; i < numOfCircle; i++)
	{
		cout << "원 " << i + 1 << "의 반지름 >> ";
		cin >> r;
		p[i].setRadius(r);
		if (p[i].getArea() > 100)
			cnt++;
	}
	cout << "면적이 100보다 큰 원은 " << cnt << "개 입니다." << endl;
	delete []p;
}