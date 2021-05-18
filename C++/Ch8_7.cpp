#include <iostream>
#include <string>
using namespace std;

class BaseMemory {
	char* mem;
protected:
	BaseMemory(int size) {
		mem = new char[size];
	}
	~BaseMemory() {
		delete[] mem;
	}
public:
	void setCh(int index, char*chArray) {
		for (int i = 0; i < index; i++)
		{
			mem[i] = chArray[i];
		}
	}
	char getCh(int index) {
		return mem[index];
	}
	void write(int index, char ch) {
		mem[index] = ch;
	}
	char read(int index) {
		return mem[index];
	}
};

class ROM : public BaseMemory
{
	int memorysize;
	char* chArray;
	int size;
public:
	ROM(int memorysize, char* chArray, int size) : BaseMemory(memorysize) {
		this->memorysize = memorysize;
		this->chArray = chArray;
		this->size = size;
		setCh(size, chArray);
	};
private:

};

class RAM : public BaseMemory
{
	int memorysize;
public:
	RAM(int memorysize) : BaseMemory(memorysize) {
		this->memorysize = memorysize;
	}

};

int main() {
	char x[5] = { 'h','e','l','l','o'};
	ROM biosROM(1024 * 10, x, 5);
	RAM mainMemory(1024 * 1024);

	for (int i = 0; i < 5; i++) 
	{
		mainMemory.write(i, biosROM.read(i));
	}
	for (int i = 0; i < 5; i++)
	{
		cout << mainMemory.read(i);
	}

}