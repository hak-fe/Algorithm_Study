#include <iostream>
using namespace std;

class Circle{
	int radius;// 원의 반지름 값
	string name; // 원의 이름
public:
	void setCircle(string name, int radius) { this->name = name; this->radius = radius; }; // 이름과 반지름 설정
	double getArea() { return radius * radius * 3.14; };
	string getName() { return name; };
};

class CircleManager{
	Circle* p; // Circle 배열에 대한 포인터
	int size; // 배열의 크기
public:
	CircleManager(int size); // size 크기의 배열을 동적 생성. 사용자로부터 입력 완료
	~CircleManager();
	void searchByName();// 사용자로부터 원의 이름을 입력받아 면적 출력
	void searchByArea(); // 사용자로부터 면적을 입력받아 면적보다 큰 원의 이름 출력
	
};

CircleManager::CircleManager(int size)
{
	string Name;
	int radius;
	this->size = size;
	p = new Circle[size];
	for (int i = 0; i < size; i++)
	{
		cout << "원 " << i + 1 << "의 이름과 반지름 >> ";
		cin >> Name >> radius;
		p[i].setCircle(Name, radius);
	}
}

CircleManager::~CircleManager()
{
}

void CircleManager::searchByName() {
	string inputName;
	cout << "검색하고자 하는 원의 이름 >> ";
	cin >> inputName;
	for (int i = 0; i < size; i++)
	{
		if (inputName == p[i].getName()) {
			cout << p[i].getName() << "의 면적은 " << p[i].getArea() << endl;
		}
	}
}

void CircleManager::searchByArea() {
	int Area;
	cout << "최소 면적을 정수로 입력하세요 >> ";
	cin >> Area;
	cout << Area << "보다 큰 원을 검색합니다." << endl;
	for (int i = 0; i < size; i++)
	{
		if (p[i].getArea() > Area) {
			cout << p[i].getName() << "의 면적은 " << p[i].getArea() << ", ";
		}
	}
}

int main() {
	int num, radius;
	string Name;
	cout << "원의 개수 >> ";
	cin >> num;
	CircleManager p(num);
	p.searchByName();
	p.searchByArea();
}
