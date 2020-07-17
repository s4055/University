#include <stdio.h>
#include <string.h>

void print(char (*c)[30]) {
	int max_length = 0;
	for (int i = 0; i < 5; i++) {
		if (strlen(c[i]) > max_length) {
			max_length = strlen(c[i]);
		}
	}
	
	printf("\n���ڿ��� ���ڰ� ���� ���� ���ڿ� ���\n");
	for (int i = 0; i < 5; i++) {
		if (strlen(c[i]) == max_length) {
			printf("���ڿ� %d : %s\n", i + 1, c[i]);
		}
	}
}

int main() {
	char ch[5][30];

	for (int i = 0; i < 5; i++) {
		printf("���ڿ� %d : ", i + 1);
		scanf("%s", ch[i]);

		if (strlen(ch[i]) >= 20) {
			printf("�ٽ� �Է��ϼ���.\n\n");
			i--;
		}
	}
	
	print(ch);
	return 0;
}