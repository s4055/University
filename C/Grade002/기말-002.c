#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, N, cnt = 1, ** arr;

	while (1) {
		printf("n X n ����� n�� �Է��Ͻÿ� : ");
		scanf("%d", &n);

		if (n % 2 == 0) {
			printf("�Է��Ͻ� ������ Ȧ���� �ƴմϴ�.\n");
		}
		else {
			N = n + 2;
			arr = (int(**))malloc(N * sizeof(int));

			for (int i = 0; i < N; i++) {
				arr[i] = (int*)malloc(N * sizeof(int));
			}

			//�迭 �ʱ�ȭ
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					arr[i][j] = 0;
				}
			}

			//������ �����, ������ ��(�밢������ 1�� ����)
			int a = 1, b = N / 2;
			arr[a][b] = 1;
			for (int k = 2; k <= n * n; k++) {
				int x = a, y = b;
				a -= 1, b += 1;

				//�迭 �ʰ�X
				if (1 <= a && a < N - 1 && 1 <= b && b < N - 1) {
					if (arr[a][b] == 0) {//��ĭ
						arr[a][b] = k;
					}
					else {//��ĭX
						arr[x + 1][y] = k;
						a = x + 1, b = y;
					}
				}

				//�迭 �ʰ�
				if ((a == 0 && b == 0) || (a == 0 && b == N - 1) || (a == N - 1 && b == 0) || (a == N - 1 && b == N - 1)) {//�糡 �𼭸�
					arr[x + 1][y] = k;
					a = x + 1, b = y;
				}
				else if (a == 0 || a == N - 1) {//����
					for (int t = N - 2; t >= 1; t--) {
						if (arr[t][b] == 0) {
							arr[t][b] = k;
							a = t;
							break;
						}
					}
				}
				else if (b == 0 || b == N - 1) {//����
					for (int t = 1; t < N - 1; t++) {
						if (arr[a][t] == 0) {
							arr[a][t] = k;
							b = t;
							break;
						}
					}
				}
			}

			//���
			for (int i = 1; i < N - 1; i++) {
				for (int j = 1; j < N - 1; j++) {
					printf("%3d ", arr[i][j]);
				}
				printf("\n");
			}
			break;
		}
	}

	return 0;
}