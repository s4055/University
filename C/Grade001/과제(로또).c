#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int print_menu(){
	//scanf롤 입력받은 정수 값을 반환하기 위해 int형을 써줌
	int a;
	scanf("%d", &a);
	return a;
}

void create_lotto(int Lotto[]){
	//배열 Lotto는 당첨번호 배열을 받는 매개변수
	srand(time(NULL));

	//로또 당첨 번호
	for (int i = 0; i < 7; i++){
		Lotto[i] = rand() % 45 + 1;
	}
}

void check_num(int Lotto[]){
	//배열 Lotto는 당첨번호 배열을 받는 매개변수
	srand(time(NULL));
	int i, j, k;

	//중복 체크
	for (i = 0; i < 7; i++){
		Lotto[i] = rand() % 45 + 1;

		for (j = 0; j < i; j++){
			if (Lotto[i] == Lotto[j]){
				i--;
			}
		}
	}
	
	//오름차순으로 정렬
	//Lotto[6]는 보너스 번호로 오름차순에서 제외
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
	//배열 ri는 입력한 로또번호 또는 자동생성한 로또번호를 받는 매개변수
	srand(time(NULL));
	int i, j, k;

	//자동생성
	for (i = 0; i < 6; i++){
		ri[i] = rand() % 45 + 1;
	}

	//오름차순으로 정렬
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
	//배열 ri는 입력한 로또번호 또는 자동생성한 로또번호를 받는 매개변수
	int i, j, k;

	printf("번호 입력 : ");
	for (i = 0; i < 6; i++){
		scanf("%d", &ri[i]);
	}

	//오름차순으로 정렬
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
	//배열 ri는 입력한 로또번호 또는 자동생성한 로또번호를 받는 매개변수
	//배열 Lotto는 당첨번호 배열을 받는 매개변수
	//rank(등수)를 반환하기 위해 int형을 써줌
	//Lotto[6]은 보너스 번호
	int count[7] = { 0 };
	int i, j, rank, sum = 0;

	//당첨번호와 비교
	//Lotto[i] ( 0<i<7 )와 ri[0] ~ ri[5]를 비교하여 같은 수가 있다면 count[i]를 1로 만들고
	//없다면 0으로 한다
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

	//결과
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
	//배열 ri는 입력한 로또번호 또는 자동생성한 로또번호를 받는 매개변수
	//배열 Lotto는 당첨번호 배열을 받는 매개변수
	//rank는 등수를 받는 매개변수
	//Lotto[6]은 보너스 번호
	int i;
	printf("당첨 번호 : ");
	for (i = 0; i < 6; i++){
		printf("%3d", Lotto[i]);
	}
	printf(", 보너스 번호 : %d \n", Lotto[6]);
	printf("출력 번호 : ");
	for (i = 0; i < 6; i++){
		printf("%3d", ri[i]);
	}
	printf("\n");
	if (rank == 1){
		printf("1등 입니다. \n");
	}
	else if (rank == 2){
		printf("2등 입니다. \n");
	}
	else if (rank == 3){
		printf("3등 입니다. \n");
	}
	else if (rank == 4){
		printf("4등 입니다. \n");
	}
	else if (rank == 5){
		printf("5등 입니다. \n");
	}
	else if (rank == 0){
		printf("꽝 입니다. \n");
	}
}

int main() {
	int Input_lotto[6];//로또 번호 입력
	int lotto[7];//로또 당첨 번호
	int Random_lotto[6];//로또 번호 자동생성
	int rank;//등수
	int i;

	printf("게임 횟수 : ");
	int a = print_menu();

	create_lotto(lotto);
	check_num(lotto);

	printf("당첨 번호 : ");
	for (i = 0; i < 6; i++){
		printf("%3d", lotto[i]);
	}
	printf(", 보너스 번호 : %d \n", lotto[6]);

	for (int i = 1; i <= a; i++){
		printf("\n %d회 \n", i);
		printf("자동생성(1) or 입력(2) => ");
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