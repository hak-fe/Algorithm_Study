#include <iostream>
#include <cstring>
using namespace std;

class Account {
	string name;
	int id;
	int balance;
public:
	Account(string Name, int Id, int Balance);
	void deposit(int n);
	string getOwner();
	int inquiry();
	int withdraw(int n);
};

Account::Account(string Name, int Id, int Balance) {
	name = Name;
	id = Id;
	balance = Balance;
}

void Account::deposit(int n) {
	balance += n;
}

string Account::getOwner() {
	return name;
}

int Account::inquiry() {
	return balance;
}

int Account::withdraw(int n) {
	return balance -= n;
}

int main(void) {
	Account a("kitae", 1, 5000);
	a.deposit(50000);
	cout << a.getOwner() << "의 잔액은" << a.inquiry() << endl;
	int money = a.withdraw(20000);
	//리턴 한 번만 해줘도 a객체의 balance맴버 변수에서 20000 이라는 값이 마이너스 된다.
	// 즉, return이 객체 a의 멤버 변수에 영향을 준다는 뜻!
	cout << a.getOwner() << "의 잔액은" << a.inquiry() << endl;
}
