#include <stdio.h>
#include <string.h>

typedef struct student {
	int num;//�й�
	char name[10];//�̸�
	int score;//����
} STUDENT;

void addList(STUDENT *s, int count) {
	if (count <= 10) {
		printf("�й� : ");
		scanf("%d", &s[count].num);
		printf("�̸� : ");
		scanf("%s", s[count].name);
		printf("���� : ");
		scanf("%d", &s[count].score);
	}
	else if (count > 10) {
		printf("�� �̻� �߰� �� �� �����ϴ�");
	}

}
void printList(STUDENT *s, int count) {
	STUDENT temp;
	int i, j;
	for (i = 0; i < count; i++) {
		for (j = 0; j < i; j++) {
			if (strcmp(s[i].name, s[j].name)<0) {
				temp = s[j];
				s[j] = s[i];
				s[i] = temp;
			}
		}
	}

	printf("�й�\t�̸�\t���� \n");
	printf("---------------------\n"); 
	for (int i = 0; i < count; i++) {
		printf("%d\t%s\t%d\n", s[i].num, s[i].name, s[i].score);
	}
}

void printStatistics(STUDENT *s, int count) {
	printf("�� �ο� : %d \n", count);

	int i, sum = 0;
	for (i = 0; i < count; i++) {
		sum += s[i].score;
	}
	printf("���� : %d \n", sum);

	double avg = (double)sum / count;
	printf("��� : %.2lf \n", avg);
}

void searchList(STUDENT *s, int count) {
	char s_name[10];
	printf("�˻� �̸� : ");
	scanf("%s", &s_name);

	for (int i = 0; i < count; i++) {
		if (strcmp(s_name, s[i].name) == 0) {
			printf("�й�\t�̸�\t���� \n");
			printf("---------------------\n");
			printf("%d\t%s\t%d\n", s[i].num, s[i].name, s[i].score);
		}
	}
}

int main() {
	STUDENT stu[10];
	char a;
	int count = 0;//�л� ��

	while (1) {
		printf("=====================\n");
		printf("�޴��� �����Ͻÿ� : ");
		scanf(" %c", &a);

		switch (a) {
			case '1': {
				printf("\n[�л� �߰�]\n");
				addList(stu, count);
				count++;
				break;
			}
			case '2': {
				printf("\n[�л� ����Ʈ ���]\n");
				printList(stu, count);
				break;
			}
			case '3': {
				printf("\n[�л� ����Ʈ ���]\n");
				printStatistics(stu, count);
				break;
			}
			case '4': {
				printf("\n[�л� ����Ʈ �˻�]\n");
				searchList(stu, count);
				break;
			}
			case 'q': {
				printf("\n����\n");
				exit(1);
			}
		}
	}
}