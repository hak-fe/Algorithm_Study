#include <iostream>
using namespace std;
class Book
{
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title; this->price = price; this->pages = pages;
	};
	void show() {
		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
	}
	string getTItle() { return title; }
	void operator+=(int price) {
		this->price += price;
	}
	void operator-=(int price) {
		this->price -= price;
	}
};

int main() {
	Book a("청춘", 20000, 300), b("미래", 30000, 500);
	a += 500;
	b -=500;
	a.show();
	b.show();
}