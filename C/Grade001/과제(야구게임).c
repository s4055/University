#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
	int i, j, turn;
	int strike = 0;
	int ball = 0;
	int b[4], a[4];
	srand(time(NULL));

	//�ߺ� ����
	for (i = 0; i < 4; i++){
		a[i] = rand() % 10;
		for (j = 0; j < i; j++){
			if (a[i] == a[j]){
				i--;
			}
		}
	}

	for (i = 0; i < 4; i++){
		printf("%2d", a[i]);
	}

	printf("\n\n--------------����--------------\n");

	for (turn = 1; turn <= 10; turn++){
		for (i = 0; i < 4; i++){
			scanf("%d", &b[i]);
		}

		//��
		for (i = 0; i < 4; i++){
			for (j = 0; j < 4; j++){
				if (a[i] == b[j]){
					if (i == j){
						strike++;
					}
					else{
						ball++;
					}
				}
			}
		}



		if (strike == 4){
			printf("%dȸ ���� => ���� \n", turn);
			printf("--------------------------------\n");
			printf("%dȸ ����, ���� \n", turn);
			break;
		}
		else if (b[3] == b[2] || b[3] == b[1] || b[3] == b[0] || b[2] == b[1] || b[2] == b[0] || b[1] == b[0]){
			printf("%dȸ ���� => �ٽ� �Է��ϼ��� \n", turn);
			strike = 0; ball = 0;
			turn--;
		}
		else if (strike == 0 && ball == 0){
			printf("%dȸ ���� => OUT \n", turn);
			strike = 0; ball = 0;
		}
		else{
			printf("%dȸ ���� => Strike : %d Ball : %d \n", turn, strike, ball);
			if (turn == 10 && strike != 4){
				printf("--------------------------------\n");
				printf("�����߽��ϴ�. \n");
			}
			strike = 0; ball = 0;
		}
	}
}
