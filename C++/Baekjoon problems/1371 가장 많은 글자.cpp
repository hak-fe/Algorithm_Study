#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	int alpha[26] = { 0, };
	vector<int>indexVector;
	string sentence;
	while (getline(cin, sentence)) {
		for (int i = 0; i < sentence.size(); i++)
		{
			alpha[sentence[i] - 97]++;
		}
	}

	int max = alpha[0];

	for (int i = 1; i < 26; i++) // 일단 최댓값 먼저 구하고
	{
		if (alpha[i] >= max) {
			max = alpha[i];
		}
	}
	for (int i = 0; i < 26; i++) //최댓값과 같은 값이 있는지 찾는다
	{// 그 인덱스를 벡터에 저장
		if (alpha[i] == max) {
			indexVector.push_back(i);
		}
	}
	for (int i = 0; i < indexVector.size(); i++)
	{
		char temp = indexVector[i] + 'a';
		cout << temp;
	}
}