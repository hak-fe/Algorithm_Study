#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int temp = 0; // n에 가장 근접한 값을 저장하는 변수
string ans = "";
void recurtion(string n, string elements, int eleSize);
int main() {
	string n, elements;
	int k;
	char ch;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> ch;
		elements += ch;
	}
	recurtion(n, elements, k);
	cout << temp;

}
void recurtion(string n, string elements, int eleSize) {

	for (int i = 0; i < eleSize; ans.pop_back(), i++)
	{
		ans += elements[i]; // 해당 원소를 담는다.
		//cout << elements[i] << "를 " << ans << "에 추가\n";
		if (stoi(ans) <= stoi(n) && stoi(ans) > temp) {
			// 만들어진 수가 n보다 작고, temp보다 큰 경우, temp에 ans를 대입.
			temp = stoi(ans);
		//	cout << "최댓값 : " << temp << '\n';
		}
		if(n.length() != ans.length())
			recurtion(n, elements, eleSize);
	}
}