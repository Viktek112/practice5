// ----------------------- matrixMin.c
#include "findMin.h"
#include <stdio.h>
#include <limits.h>

void findMin(const int* const p, int size) {
	int* res = malloc(sizeof(int) * size);
	int numOfDoubles = 0;
	int numOfRows = 0;
	int min = INT_MAX;
	int i;
	for (i = 0; i < size; i++) {
		if (*(p + i) < min) {
			min = *(p + i);
			res[0] = i % 5;
			res[1] = numOfRows;
			numOfDoubles = 0;
		}
		else if (*(p + i) == min) {
			numOfDoubles++;
			res[numOfDoubles * 2] = i % 5;
			res[numOfDoubles * 2 + 1] = numOfRows;
		}
		if ((i + 1) % 5 == 0) numOfRows++;
	}
	printf("Positions of minimal numbers are: ");
	for (i = 0; i < numOfDoubles*2+2; i+=2) {
		printf("(%d,%d)", res[i]+1, res[i+1]+1);
		if (i != numOfDoubles * 2) printf(", ");
		else printf(".\n");
	}
	free(res);
}
