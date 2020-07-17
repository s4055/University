#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char* p[5], * str;
	int idx[5] = { 0, }, cnt, size, max = 0;

	for (int i = 0; i < 5; i++) {
		cnt = 0, size = 10;
		str = (char*)malloc(sizeof(char) * size);

		printf("¹®ÀÚ¿­ %d : ", i + 1);

		while ((str[cnt] = getchar()) != '\n') {
			str = (char*)realloc(str, strlen(str));
			cnt++;
		}
		idx[i] = cnt;

		if (idx[i] > max) max = idx[i];
		p[i] = str;
	}

	int check[5] = { 0, }, n = 1;
	for (int i = max; i >= 0; i--) {
		for (int j = 0; j < 5; j++) {
			if (i == idx[j]) {
				check[j] = n;
				n++;
			}
		}
	}
	printf("\n----------------------------------------------------------\n");
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (check[j] == i + 1) {
				printf("%d", check[j]);
				if (check[j] == 1) printf("st : ");
				else if (check[j] == 2) printf("nd : ");
				else if (check[j] == 3) printf("rd : ");
				else printf("th : ");

				for (int t = 0; t < idx[j]; t++) {
					printf("%c", p[j][t]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}