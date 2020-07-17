#include <stdio.h>
#include <string.h>

typedef struct student {
	int num;//학번
	char name[10];//이름
	int score;//점수
} STUDENT;

void addList(STUDENT *s, int count) {
	if (count <= 10) {
		printf("학번 : ");
		scanf("%d", &s[count].num);
		printf("이름 : ");
		scanf("%s", s[count].name);
		printf("점수 : ");
		scanf("%d", &s[count].score);
	}
	else if (count > 10) {
		printf("더 이상 추가 할 수 없습니다");
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

	printf("학번\t이름\t점수 \n");
	printf("---------------------\n"); 
	for (int i = 0; i < count; i++) {
		printf("%d\t%s\t%d\n", s[i].num, s[i].name, s[i].score);
	}
}

void printStatistics(STUDENT *s, int count) {
	printf("총 인원 : %d \n", count);

	int i, sum = 0;
	for (i = 0; i < count; i++) {
		sum += s[i].score;
	}
	printf("총점 : %d \n", sum);

	double avg = (double)sum / count;
	printf("평균 : %.2lf \n", avg);
}

void searchList(STUDENT *s, int count) {
	char s_name[10];
	printf("검색 이름 : ");
	scanf("%s", &s_name);

	for (int i = 0; i < count; i++) {
		if (strcmp(s_name, s[i].name) == 0) {
			printf("학번\t이름\t점수 \n");
			printf("---------------------\n");
			printf("%d\t%s\t%d\n", s[i].num, s[i].name, s[i].score);
		}
	}
}

int main() {
	STUDENT stu[10];
	char a;
	int count = 0;//학생 수

	while (1) {
		printf("=====================\n");
		printf("메뉴를 선택하시오 : ");
		scanf(" %c", &a);

		switch (a) {
			case '1': {
				printf("\n[학생 추가]\n");
				addList(stu, count);
				count++;
				break;
			}
			case '2': {
				printf("\n[학생 리스트 출력]\n");
				printList(stu, count);
				break;
			}
			case '3': {
				printf("\n[학생 리스트 통계]\n");
				printStatistics(stu, count);
				break;
			}
			case '4': {
				printf("\n[학생 리스트 검색]\n");
				searchList(stu, count);
				break;
			}
			case 'q': {
				printf("\n종료\n");
				exit(1);
			}
		}
	}
}