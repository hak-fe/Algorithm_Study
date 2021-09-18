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
	int age; // 나이
	char name[101]; // 이름
	int order; // 가입한 순서
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
		cin >> people[i].age >> people[i].name; // 나이와 이름은 입력받고
		people[i].order = i; // 순번은 i값을 넣음
	}
	sort(people, people + n, compare);
	for (int i = 0; i < n; i++)
	{
		cout << people[i].age <<' '<< people[i].name << '\n';
	}
}