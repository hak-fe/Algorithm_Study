#include <iostream>
#include <string>
using namespace std;

class Trace {
	static string tag[100];
	static string info[100];
	static int size;
public:
	static void put(string tag, string debugingInfo);
	static void print(string tag);
	static void print();
};

int Trace::size = 0;
string Trace::tag[100];
string Trace::info[100];

void Trace::put(string t, string debugingInfo) {
	tag[size] = t;
	info[size] = debugingInfo;
	size++;
}
void Trace::print(string t) {
	cout << "----- " << t << "�±��� Trace ������ ����մϴ�. -----" << endl;
	for (int i = 0; i < size; i++)
	{
		if (t == tag[i]) {
			cout << tag[i] << ":" << info[i] << endl;
		}
	}
}
void Trace::print() {
	cout << "----- " <<"��� �±��� Trace ������ ����մϴ�. -----" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << tag[i] << ":" << info[i] << endl;
	}
}

void f() {
	int a, b, c;
	cout << "�� ���� ������ �Է��ϼ���>>";
	cin >> a >> b;
	Trace::put("f()", "������ �Է� �޾���");
	c = a + b;
	Trace::put("f()", "�� ���");
	cout << "���� " << c << endl;
}

int main(void) {
	Trace::put("main()", "���α׷��� �����մϴ�");
	f();
	Trace::put("main()", "����");

	Trace::print("f()");
	Trace::print();
}