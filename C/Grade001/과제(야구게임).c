#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
	int i, j, turn;
	int strike = 0;
	int ball = 0;
	int b[4], a[4];
	srand(time(NULL));

	//중복 제거
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

	printf("\n\n--------------공격--------------\n");

	for (turn = 1; turn <= 10; turn++){
		for (i = 0; i < 4; i++){
			scanf("%d", &b[i]);
		}

		//비교
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
			printf("%d회 공격 => 성공 \n", turn);
			printf("--------------------------------\n");
			printf("%d회 공격, 성공 \n", turn);
			break;
		}
		else if (b[3] == b[2] || b[3] == b[1] || b[3] == b[0] || b[2] == b[1] || b[2] == b[0] || b[1] == b[0]){
			printf("%d회 공격 => 다시 입력하세요 \n", turn);
			strike = 0; ball = 0;
			turn--;
		}
		else if (strike == 0 && ball == 0){
			printf("%d회 공격 => OUT \n", turn);
			strike = 0; ball = 0;
		}
		else{
			printf("%d회 공격 => Strike : %d Ball : %d \n", turn, strike, ball);
			if (turn == 10 && strike != 4){
				printf("--------------------------------\n");
				printf("실패했습니다. \n");
			}
			strike = 0; ball = 0;
		}
	}
}
