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

void add(ListHead *h, element num) {//�߰�
	ListNode* newNode;
	ListNode* tmp = NULL;
	ListNode* k;
	newNode = (ListNode*)malloc(sizeof(ListNode));

	if (h->head == NULL) {//����ִٸ�
		h->head = newNode;
		newNode->link = NULL;
	}
	else {//������� �ʴٸ�
		k = h->head;
		if (k->link == NULL) {//��� 1��
			if (k->data > num) {//Ŭ ��
				tmp = h->head;
				h->head = newNode;
				newNode->link = tmp;
			}
			else {//�۰ų� ���� ��
				k->link = newNode;
				newNode->link = NULL;
			}
		}
		else {//��� 2���̻�
			while (k->link != NULL) {//������ ������
				k = k->link;
			}

			//������ ��� data�� ��
			if (k->data < num) {//Ŭ ��
				k->link = newNode;
				newNode->link = NULL;
			}
			else {//�۰ų� ���� ��
				k = h->head;
				while (k->data < num) {
					tmp = k;
					k = k->link;
				}

				if (k == h->head) {//ù��° ����� ���
					tmp = h->head;
					h->head = newNode;
					newNode->link = tmp;
				}
				else {//�� �̿�
					tmp->link = newNode;
					newNode->link = k;
				}
			}
		}
	}
	newNode->data = num;
}

void del(ListHead *h, element num) {//����
	ListNode* tmp;
	ListNode* k;

	k = h->head;
	while (num != k->data) {
		tmp = k;
		k = k->link;
	}

	//��� 1��
	if (h->head->link == NULL) {
		h->head = NULL;
	}
	else {//��� 2�� �̻�
		if (k == h->head) {//����
			h->head = h->head->link;
		}
		else if (k->link == NULL) {//��
			tmp->link = k->link;//k->link : NULL
		}
		else {//�߰�
			tmp->link = k->link;
		}
	}
}

void print(ListHead *h) {//���
	ListNode* k;

	k = h->head;
	while (k != NULL) {
		printf("%d\t", k->data);
		k = k->link;
	}
	printf("\n");
}

int check(ListHead* h, element num) {//����ִ��� üũ, ã�� ���� �ִ���
	ListNode* k;

	if (h->head != NULL) {//������� �ʴٸ�
		k = h->head;
		while (num != k->data) {
			if (k->link == NULL) return -1;//ã�°��� ���ٸ�
			k = k->link;
		}
		return 1;//ã�°��� �ִٸ�
	}
	return -1;//����ִٸ�
}

int main() {
	element n, num;
	ListHead* h;
	ListNode* p;

	//��� ����
	h = (ListHead*)malloc(sizeof(ListHead));
	h->head = NULL;

	printf("���Ḯ��Ʈ ���α׷��Դϴ�.\n");
	while (1) {
		if (h->head != NULL) {
			print(h);
		}
		printf("1. ����\t2. ����\t3. ����\n");
		printf("�޴��� �����ϼ��� : ");
		scanf("%d", &n);

		if (n == 1) {
			printf("������ ������ �Է��ϼ��� : ");
			scanf("%d", &num);
			add(h, num);
		}
		else if (n == 2) {
			printf("������ ������ �Է��ϼ��� : ");
			scanf("%d", &num);

			if (check(h, num) == 1) del(h, num);//������� �ʰ� ã�°��� �ִ� ���
			else printf("---- �ٽ� �Է��ϼ���. ----\n");
		}
		else if (n == 3) {
			printf("���α׷��� �����մϴ�.");
			break;
		}
		else {
			printf("---- �ٽ� �Է��ϼ���. ----\n");
		}
		printf("\n");
	}

	return 0;
}