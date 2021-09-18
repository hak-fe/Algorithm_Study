#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <deque>

struct People
{
	int age; // ����
	char name[101]; // �̸�
	int order; // ������ ����
};

bool compare(People p1, People p2) 
{
	if (p1.age < p2.age)
		return true;
	else if (p1.age > p2.age)
		return false;
	else {
		if (p1.order < p2.order)
			return true;
		else
			return false;

	}
}

using namespace std;
int main()
{
	int n;
	cin >> n;
	People* people = new People[n];
	for (int i = 0; i < n; i++)
	{
		cin >> people[i].age >> people[i].name; // ���̿� �̸��� �Է¹ް�
		people[i].order = i; // ������ i���� ����
	}
	sort(people, people + n, compare);
	for (int i = 0; i < n; i++)
	{
		cout << people[i].age <<' '<< people[i].name << '\n';
	}
}