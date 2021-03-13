#include <iostream>
#include <cstring>
using namespace std;

int main(void) {

	int FIrst_Num = 0, Last_Num = 0;
	char ch;
	
	while (1) {
		cout << "°è»ê½Ä? ";
		cin >> FIrst_Num >> ch >> Last_Num;
		if (ch == '+') {
			cout << FIrst_Num << " " << ch << " " << Last_Num << " = " << FIrst_Num + Last_Num << endl;
		}
		else if (ch == '-') {
			cout << FIrst_Num << " " << ch << " " << Last_Num << " = " << FIrst_Num - Last_Num << endl;
		}
		else if (ch == '*') {
			cout << FIrst_Num << " " << ch << " " << Last_Num << " = " << FIrst_Num * Last_Num << endl;
		}
		else if (ch == '/') {
			cout << FIrst_Num << " " << ch << " " << Last_Num << " = " << FIrst_Num / Last_Num << endl;
		}
		else if (ch == '%') {
			cout << FIrst_Num << " " << ch << " " << Last_Num << " = " << FIrst_Num % Last_Num << endl;
		}
	}
}