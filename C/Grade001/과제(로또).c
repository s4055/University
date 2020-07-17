#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int print_menu(){
	//scanf�� �Է¹��� ���� ���� ��ȯ�ϱ� ���� int���� ����
	int a;
	scanf("%d", &a);
	return a;
}

void create_lotto(int Lotto[]){
	//�迭 Lotto�� ��÷��ȣ �迭�� �޴� �Ű�����
	srand(time(NULL));

	//�ζ� ��÷ ��ȣ
	for (int i = 0; i < 7; i++){
		Lotto[i] = rand() % 45 + 1;
	}
}

void check_num(int Lotto[]){
	//�迭 Lotto�� ��÷��ȣ �迭�� �޴� �Ű�����
	srand(time(NULL));
	int i, j, k;

	//�ߺ� üũ
	for (i = 0; i < 7; i++){
		Lotto[i] = rand() % 45 + 1;

		for (j = 0; j < i; j++){
			if (Lotto[i] == Lotto[j]){
				i--;
			}
		}
	}
	
	//������������ ����
	//Lotto[6]�� ���ʽ� ��ȣ�� ������������ ����
	for (i = 0; i < 5; i++){
		for (j = i + 1; j < 6; j++){
			if (Lotto[i] > Lotto[j]){
				k = Lotto[i];
				Lotto[i] = Lotto[j];
				Lotto[j] = k;
			}
		}
	}
}

void random_lotto(int ri[]){
	//�迭 ri�� �Է��� �ζǹ�ȣ �Ǵ� �ڵ������� �ζǹ�ȣ�� �޴� �Ű�����
	srand(time(NULL));
	int i, j, k;

	//�ڵ�����
	for (i = 0; i < 6; i++){
		ri[i] = rand() % 45 + 1;
	}

	//������������ ����
	for (i = 0; i < 5; i++){
		for (j = i + 1; j < 6; j++){
			if (ri[i] > ri[j]){
				k = ri[i];
				ri[i] = ri[j];
				ri[j] = k;
			}
		}
	}
}

void input_lotto(int ri[]){
	//�迭 ri�� �Է��� �ζǹ�ȣ �Ǵ� �ڵ������� �ζǹ�ȣ�� �޴� �Ű�����
	int i, j, k;

	printf("��ȣ �Է� : ");
	for (i = 0; i < 6; i++){
		scanf("%d", &ri[i]);
	}

	//������������ ����
	for (i = 0; i < 5; i++){
		for (j = i + 1; j < 6; j++){
			if (ri[i] > ri[j]){
				k = ri[i];
				ri[i] = ri[j];
				ri[j] = k;
			}
		}
	}
}

int win_lotto(int ri[], int Lotto[]){
	//�迭 ri�� �Է��� �ζǹ�ȣ �Ǵ� �ڵ������� �ζǹ�ȣ�� �޴� �Ű�����
	//�迭 Lotto�� ��÷��ȣ �迭�� �޴� �Ű�����
	//rank(���)�� ��ȯ�ϱ� ���� int���� ����
	//Lotto[6]�� ���ʽ� ��ȣ
	int count[7] = { 0 };
	int i, j, rank, sum = 0;

	//��÷��ȣ�� ��
	//Lotto[i] ( 0<i<7 )�� ri[0] ~ ri[5]�� ���Ͽ� ���� ���� �ִٸ� count[i]�� 1�� �����
	//���ٸ� 0���� �Ѵ�
	for (i = 0; i < 7; i++){
		for (j = 0; j < 6; j++){
			if (Lotto[i] == ri[j]){
				count[i]++;
			}
			if (count[i] == 1){
				break;
			}
		}
	}

	for (i = 0; i < 7; i++){
		sum = count[i] + sum;
	}

	//���
	if (sum == 6 && count[6]==0){
		rank = 1;
	}
	else if (sum == 6 && count[6] == 1){
		rank = 2;
	}
	else if (sum == 5 && count[6] == 0){
		rank = 3;
	}
	else if (sum == 4 && count[6] == 0){
		rank = 4;
	}
	else if (sum == 3 && count[6] == 0){
		rank = 5;
	}
	else{
		rank = 0;
	}

	return rank;
}

void print_lotto(int ri[], int Lotto[], int rank){
	//�迭 ri�� �Է��� �ζǹ�ȣ �Ǵ� �ڵ������� �ζǹ�ȣ�� �޴� �Ű�����
	//�迭 Lotto�� ��÷��ȣ �迭�� �޴� �Ű�����
	//rank�� ����� �޴� �Ű�����
	//Lotto[6]�� ���ʽ� ��ȣ
	int i;
	printf("��÷ ��ȣ : ");
	for (i = 0; i < 6; i++){
		printf("%3d", Lotto[i]);
	}
	printf(", ���ʽ� ��ȣ : %d \n", Lotto[6]);
	printf("��� ��ȣ : ");
	for (i = 0; i < 6; i++){
		printf("%3d", ri[i]);
	}
	printf("\n");
	if (rank == 1){
		printf("1�� �Դϴ�. \n");
	}
	else if (rank == 2){
		printf("2�� �Դϴ�. \n");
	}
	else if (rank == 3){
		printf("3�� �Դϴ�. \n");
	}
	else if (rank == 4){
		printf("4�� �Դϴ�. \n");
	}
	else if (rank == 5){
		printf("5�� �Դϴ�. \n");
	}
	else if (rank == 0){
		printf("�� �Դϴ�. \n");
	}
}

int main() {
	int Input_lotto[6];//�ζ� ��ȣ �Է�
	int lotto[7];//�ζ� ��÷ ��ȣ
	int Random_lotto[6];//�ζ� ��ȣ �ڵ�����
	int rank;//���
	int i;

	printf("���� Ƚ�� : ");
	int a = print_menu();

	create_lotto(lotto);
	check_num(lotto);

	printf("��÷ ��ȣ : ");
	for (i = 0; i < 6; i++){
		printf("%3d", lotto[i]);
	}
	printf(", ���ʽ� ��ȣ : %d \n", lotto[6]);

	for (int i = 1; i <= a; i++){
		printf("\n %dȸ \n", i);
		printf("�ڵ�����(1) or �Է�(2) => ");
		int b = print_menu();

		if (b == 1){
			random_lotto(Random_lotto);
			rank = win_lotto(Random_lotto, lotto);
			print_lotto(Random_lotto, lotto, rank);
		}
		else if (b == 2){
			input_lotto(Input_lotto);
			rank = win_lotto(Input_lotto, lotto);
			print_lotto(Input_lotto, lotto, rank);
		}
	}
}