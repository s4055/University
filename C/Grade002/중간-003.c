#include <stdio.h>
#include <string.h>

typedef struct student {
	char name[20];
	int num, total;
} STUDENT;

void sort_name(STUDENT *s) {
	STUDENT tmp;
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (strcmp(s[i].name, s[j].name) > 0) {
				tmp = s[i];
				s[i] = s[j];
				s[j] = tmp;
			}
		}
	}
}

void sort_num(STUDENT *s) {
	STUDENT tmp;
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (s[i].num > s[j].num) {
				tmp = s[i];
				s[i] = s[j];
				s[j] = tmp;
			}
		}
	}
}

void sort_total(STUDENT *s) {
	STUDENT tmp;
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (s[i].total < s[j].total) {
				tmp = s[i];
				s[i] = s[j];
				s[j] = tmp;
			}
		}
	}
}

void print(STUDENT *s) {
	printf("--------------------------------------\n");
	printf("�̸�\t�й�\t\t����");
	printf("\n--------------------------------------\n");
	for (int i = 0; i < 5; i++) {
		printf("%s\t%d\t%d\n", s[i].name, s[i].num, s[i].total);
	}
	printf("\n");
}

int main() {
	STUDENT stu[5];

	for (int i = 0; i < 5; i++) {
		printf("�л� %d ����\n", i + 1);
		printf("�̸� : ");
		scanf("%s", &stu[i].name);
		printf("�й� : ");
		scanf("%d", &stu[i].num);
		printf("���� : ");
		scanf("%d", &stu[i].total);
		printf("\n");
	}

	int choice;
	while (1) {
		printf("1. �̸� ��(ABC��)\t2. �й���(��������)\t3. ����(��������)\t0. ����\n");
		printf("���ϴ� ������ �Է��Ͻÿ� : ");
		scanf("%d", &choice);

		switch (choice) {
		case 0:
			printf("\n�����մϴ�.\n");
			return 0;
			break;
		case 1:
			sort_name(stu);
			print(stu);
			break;
		case 2:
			sort_num(stu);
			print(stu);
			break;
		case 3:
			sort_total(stu);
			print(stu);
			break;
		default:
			printf("\n�ٽ� �Է��ϼ���.\n\n");
		}
	}
	return 0;
}