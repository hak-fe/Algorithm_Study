#include <iostream>
#include <string>
using namespace std;
#define MAX 10000001
int main() {
	int n, cnt = 0;
	int min = MAX;
	cin >> n;
	for (int i = 1; i <= MAX; i++)
	{
		string temp = to_string(i);
		if (temp.find("666") != string::npos) {
			cnt++;
		}
		if (cnt == n) {
			if (stoi(temp) < min)
				min = stoi(temp);
			break;
		}
	}
	cout << min;
}