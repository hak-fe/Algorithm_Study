#include <iostream>
using namespace std;

class Histogram{
	string str;
	int cnt;
public:
	Histogram();
	Histogram(string str);
	~Histogram();
	void put(string strput);
	void putc(char ch);
	void print();
};

Histogram::Histogram(){
	str = "";
	cnt = 0;
}

Histogram::Histogram(string str) {
	this->str = str;
	cnt = 0;
	cout << str << '\n';
}

Histogram::~Histogram(){

}

void Histogram::put(string strput) {
	cout << strput;
	str += strput;
}

void Histogram::putc(char ch) {
	cout << ch;
	str += ch;
}

void Histogram::print() {


	for (int i = 0; i < str.length(); i++) // ¼Ò¹®ÀÚ·Î ¹Ù²Ù±â
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
	}

	for (int i = 0; i < str.length(); i++) // ¾ËÆÄºª °¹¼ö ±¸ÇÏ±â
	{
		if (str[i] >= 97 && str[i] <= 122)
			cnt++;
	}

	cout << "\n\n" << "ÃÑ ¾ËÆÄºª ¼ö " << cnt << "\n\n";	
	
	for (char ch = 'a'; ch <= 'z'; ch++)
	{
		int chCount = 0;
		string star;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == ch) {
				chCount++;
			}
		}
		for (int s = 0; s < chCount; s++)
		{
			star += '*';
		}
		cout << ch << " (" << chCount << ")      : " << star << endl;
	}
}

int main(void) {
	Histogram elvisHisto("Wise men say, only fools rush in But I can't help, ");
	elvisHisto.put("falling in love with you");
	elvisHisto.putc('-');
	elvisHisto.put("Elvis Presley");
	elvisHisto.print();
}