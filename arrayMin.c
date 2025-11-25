// ----------------------- arrayMin.c
#include "findMin.h"
#include <stdio.h>
#include <limits.h>

void findMin(const int* const p, int size) {
	int* res = malloc(sizeof(int) * size);
	int numOfDoubles;
	int min = INT_MAX;
	int i;
	for (i = 0; i < size; i++) {
		if (*(p + i) < min) {
			min = *(p + i);
			res[0] = i;
			numOfDoubles = 0;
		}
		else if (*(p + i) == min) {
			numOfDoubles++;
			res[numOfDoubles] = i;
		}
	}
	printf("Positions of minimal numbers are: ");
	for (i = 0; i <= numOfDoubles; i++) {
		printf("%d", res[i] + 1);
		if (i != numOfDoubles) printf(", ");
		else printf(".\n");
	}
	free(res);
}
