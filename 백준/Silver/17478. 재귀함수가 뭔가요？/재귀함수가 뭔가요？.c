#include <stdio.h>
#include <string.h>
char* question = "\"재귀함수가 뭔가요?\"";
char* fake_answer[3] = {
	"\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n",
	"마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n",
	"그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n"
};
char* real_answer = "\"재귀함수는 자기 자신을 호출하는 함수라네\"";
char* end = "라고 답변하였지.\n";
char* lines = "____";
void recursion(int n);
int temp;
int main() {
	int n;
	scanf(" %d", &n);
	temp = n;
	printf("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n");
	recursion(n);
	return 0;
}
void recursion(int n) {
	for (int i = n; i < temp; i++) printf("%s", lines);
	printf("%s\n", question);
	if (n == 0) {
		for (int i = n; i < temp; i++) printf("%s", lines);
		printf("%s\n", real_answer);
		for (int i = n; i < temp; i++) printf("%s", lines);
		printf("%s", end);
		return;
	}
	else {
		for (int i = 0; i < 3; i++)
		{
			for (int j = n; j < temp; j++) printf("%s", lines);
			printf("%s", fake_answer[i]);
		}
	}
	recursion(n - 1);
	for (int i = n; i < temp; i++) printf("%s", lines);
	printf("%s", end);
	return;
}