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
	printf("이름\t학번\t\t총점");
	printf("\n--------------------------------------\n");
	for (int i = 0; i < 5; i++) {
		printf("%s\t%d\t%d\n", s[i].name, s[i].num, s[i].total);
	}
	printf("\n");
}

int main() {
	STUDENT stu[5];

	for (int i = 0; i < 5; i++) {
		printf("학생 %d 정보\n", i + 1);
		printf("이름 : ");
		scanf("%s", &stu[i].name);
		printf("학번 : ");
		scanf("%d", &stu[i].num);
		printf("총점 : ");
		scanf("%d", &stu[i].total);
		printf("\n");
	}

	int choice;
	while (1) {
		printf("1. 이름 순(ABC순)\t2. 학번순(오름차순)\t3. 총점(내림차순)\t0. 종료\n");
		printf("원하는 정렬을 입력하시오 : ");
		scanf("%d", &choice);

		switch (choice) {
		case 0:
			printf("\n종료합니다.\n");
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
			printf("\n다시 입력하세요.\n\n");
		}
	}
	return 0;
}