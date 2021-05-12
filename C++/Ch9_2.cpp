#include <iostream>
#include <string>

using namespace std;

class Converter
{
protected:
	double ratio;
	virtual double convert(double src) = 0;
	virtual string getSourceString() = 0;
	virtual string getDestString() = 0;
public:
	Converter(double ratio) { this->ratio = ratio; }
	void run() {
		double src;
		cout << getSourceString() << "�� " << getDestString() << "�� �ٲߴϴ�. ";
		cout << getSourceString() << "�� �Է��ϼ���>> ";
		cin >> src;
		cout << "��ȯ ��� : " << convert(src) << getDestString() << endl;
	}
};

class KmToMile : public Converter {
	string source;
	string dest;
public:
	KmToMile(double mile) : Converter(ratio) {
		ratio = mile;
	}
	virtual double convert(double src) {
		return src / ratio;
	}
	virtual string getSourceString() {
		return "Km";
	}
	virtual string getDestString() {
		return "Mile";
	}
};
int main() {
	KmToMile toMile(1.609344);
	toMile.run();
}