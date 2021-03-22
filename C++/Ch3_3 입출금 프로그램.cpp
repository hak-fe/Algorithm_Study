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
	cout << a.getOwner() << "�� �ܾ���" << a.inquiry() << endl;
	int money = a.withdraw(20000);
	//���� �� ���� ���൵ a��ü�� balance�ɹ� �������� 20000 �̶�� ���� ���̳ʽ� �ȴ�.
	// ��, return�� ��ü a�� ��� ������ ������ �شٴ� ��!
	cout << a.getOwner() << "�� �ܾ���" << a.inquiry() << endl;
}