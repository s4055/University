#include <stdio.h>
#include <string.h>

void print(char (*c)[30]) {
	char tmp[30];
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (strlen(c[i]) < strlen(c[j])) {
				strcpy(tmp, c[i]);
				strcpy(c[i], c[j]);
				strcpy(c[j], tmp);
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		printf("%d", i + 1);
		if (i == 0) printf("st : ");
		else if (i == 1) printf("nd : ");
		else if (i == 2) printf("rd : ");
		else printf("th : ");
		puts(c[i]);
	}
}

int main() {
	char ch[5][30];

	for (int i = 0; i < 5; i++) {
		printf("문자열 %d : ", i + 1);
		gets(ch[i]);

		if (strlen(ch[i]) >= 20) {
			printf("다시 입력하세요.\n\n");
			i--;
		}
	}
	
	printf("\n----------------------------------------------------------\n");
	print(ch);
	return 0;
}