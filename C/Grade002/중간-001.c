#include <stdio.h>
#include <string.h>

void print(char (*c)[30]) {
	int max_length = 0;
	for (int i = 0; i < 5; i++) {
		if (strlen(c[i]) > max_length) {
			max_length = strlen(c[i]);
		}
	}
	
	printf("\n문자열에 문자가 가장 많은 문자열 출력\n");
	for (int i = 0; i < 5; i++) {
		if (strlen(c[i]) == max_length) {
			printf("문자열 %d : %s\n", i + 1, c[i]);
		}
	}
}

int main() {
	char ch[5][30];

	for (int i = 0; i < 5; i++) {
		printf("문자열 %d : ", i + 1);
		scanf("%s", ch[i]);

		if (strlen(ch[i]) >= 20) {
			printf("다시 입력하세요.\n\n");
			i--;
		}
	}
	
	print(ch);
	return 0;
}