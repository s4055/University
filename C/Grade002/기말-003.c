#include <stdio.h>
#include <stdlib.h>
typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

typedef struct {
	ListNode* head;
} ListHead;

void add(ListHead *h, element num) {//추가
	ListNode* newNode;
	ListNode* tmp = NULL;
	ListNode* k;
	newNode = (ListNode*)malloc(sizeof(ListNode));

	if (h->head == NULL) {//비어있다면
		h->head = newNode;
		newNode->link = NULL;
	}
	else {//비어있지 않다면
		k = h->head;
		if (k->link == NULL) {//노드 1개
			if (k->data > num) {//클 때
				tmp = h->head;
				h->head = newNode;
				newNode->link = tmp;
			}
			else {//작거나 같을 때
				k->link = newNode;
				newNode->link = NULL;
			}
		}
		else {//노드 2개이상
			while (k->link != NULL) {//마지막 노드까지
				k = k->link;
			}

			//마지막 노드 data와 비교
			if (k->data < num) {//클 때
				k->link = newNode;
				newNode->link = NULL;
			}
			else {//작거나 같을 때
				k = h->head;
				while (k->data < num) {
					tmp = k;
					k = k->link;
				}

				if (k == h->head) {//첫번째 노드일 경우
					tmp = h->head;
					h->head = newNode;
					newNode->link = tmp;
				}
				else {//그 이외
					tmp->link = newNode;
					newNode->link = k;
				}
			}
		}
	}
	newNode->data = num;
}

void del(ListHead *h, element num) {//삭제
	ListNode* tmp;
	ListNode* k;

	k = h->head;
	while (num != k->data) {
		tmp = k;
		k = k->link;
	}

	//노드 1개
	if (h->head->link == NULL) {
		h->head = NULL;
	}
	else {//노드 2개 이상
		if (k == h->head) {//시작
			h->head = h->head->link;
		}
		else if (k->link == NULL) {//끝
			tmp->link = k->link;//k->link : NULL
		}
		else {//중간
			tmp->link = k->link;
		}
	}
}

void print(ListHead *h) {//출력
	ListNode* k;

	k = h->head;
	while (k != NULL) {
		printf("%d\t", k->data);
		k = k->link;
	}
	printf("\n");
}

int check(ListHead* h, element num) {//비어있는지 체크, 찾는 값이 있는지
	ListNode* k;

	if (h->head != NULL) {//비어있지 않다면
		k = h->head;
		while (num != k->data) {
			if (k->link == NULL) return -1;//찾는값이 없다면
			k = k->link;
		}
		return 1;//찾는값이 있다면
	}
	return -1;//비어있다면
}

int main() {
	element n, num;
	ListHead* h;
	ListNode* p;

	//헤드 생성
	h = (ListHead*)malloc(sizeof(ListHead));
	h->head = NULL;

	printf("연결리스트 프로그램입니다.\n");
	while (1) {
		if (h->head != NULL) {
			print(h);
		}
		printf("1. 삽입\t2. 삭제\t3. 종료\n");
		printf("메뉴를 선택하세요 : ");
		scanf("%d", &n);

		if (n == 1) {
			printf("삽입할 정수를 입력하세요 : ");
			scanf("%d", &num);
			add(h, num);
		}
		else if (n == 2) {
			printf("삭제할 정수를 입력하세요 : ");
			scanf("%d", &num);

			if (check(h, num) == 1) del(h, num);//비어있지 않고 찾는값이 있는 경우
			else printf("---- 다시 입력하세요. ----\n");
		}
		else if (n == 3) {
			printf("프로그램을 종료합니다.");
			break;
		}
		else {
			printf("---- 다시 입력하세요. ----\n");
		}
		printf("\n");
	}

	return 0;
}