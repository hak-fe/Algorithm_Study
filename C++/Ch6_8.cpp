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
	cout << "----- " << t << "태그의 Trace 정보를 출력합니다. -----" << endl;
	for (int i = 0; i < size; i++)
	{
		if (t == tag[i]) {
			cout << tag[i] << ":" << info[i] << endl;
		}
	}
}
void Trace::print() {
	cout << "----- " <<"모든 태그의 Trace 정보를 출력합니다. -----" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << tag[i] << ":" << info[i] << endl;
	}
}

void f() {
	int a, b, c;
	cout << "두 개의 정수를 입력하세요>>";
	cin >> a >> b;
	Trace::put("f()", "정수를 입력 받았음");
	c = a + b;
	Trace::put("f()", "합 계산");
	cout << "합은 " << c << endl;
}

int main(void) {
	Trace::put("main()", "프로그램을 시작합니다");
	f();
	Trace::put("main()", "종료");

	Trace::print("f()");
	Trace::print();
}