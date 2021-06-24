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
		cout << title << ' ' << price << "¿ø " << pages << " ÆäÀÌÁö" << endl;
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
	Book a("Ã»Ãá", 20000, 300), b("¹Ì·¡", 30000, 500);
	a += 500;
	b -=500;
	a.show();
	b.show();
}
