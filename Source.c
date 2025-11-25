// ----------------------- Source.c
#include "load.h"
#include <stdio.h>
#include <stdlib.h>

void print_matrix(int* matrix, int rows, int cols) {
    printf("\nMatrix:\n");
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%5d ", *(matrix + i * cols + j));
        }
        printf("\n");
    }
}

void print_array(int* array, int size) {
    printf("\nArray:\n");
    int i;
    for (i = 0; i < size; i++) {
        printf("%4d ", *(array + i));
    }
    printf("\n");
}

int* fillMatrix(int rows, int cols) {
    int i, j;
    int* matrix = malloc(sizeof(int)*rows*cols);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++)
            *(matrix + i * cols + j) = rand()%101-50;
    }
    return matrix;
}

int* fillArray(int size) {
    int i;
    int* array = malloc(sizeof(int) * size);
    for (i = 0; i < size; i++) 
        *(array + i) = rand() % 101 - 50;
    return array;
}

#ifdef _WIN32

int main() {
    srand(time(NULL));
    int* A = fillArray(35);
    int* B = fillMatrix(8, 5);
    print_matrix(B, 8, 5);
    print_array(A, 35);
    int input;
    int result = -1;
    do {
        if (result == 0) {
            char c;
            while ((c = getchar()) != '\n' && c != EOF) {}
        }
        printf("I will work with matrix(1)/array(2)/exit(0): ");
    } while (!(result = scanf("%d", &input)) || input < 0 || input > 2);

    if (input == 1) LoadRun("matrixLib.dll", B, 8 * 5);
    else if (input == 2) LoadRun("arrayLib.dll", A, 35);
    getch();
    return 0;	// Завершаем программу с кодом успеха 0
}

#else // Linux

int main() {
    srand(time(NULL));
    int* A = fillArray(35);
    int* B = fillMatrix(8, 5);
    print_matrix(B, 8, 5);
    print_array(A, 35);
    int input;
    int result = -1;
    do {
        if (result == 0) {
            char c;
            while ((c = getchar()) != '\n' && c != EOF) {}
        }
        printf("I will work with matrix(1)/array(2)/exit(0): ");
    } while (!(result = scanf("%d", &input)) || input < 0 || input > 2);

    if (input == 1) LoadRun("matrixLib.so", B, 8 * 5);
    else if (input == 2) LoadRun("arrayLib.so", A, 35);
    getch();
    return 0;	// Завершаем программу с кодом успеха 0
}

#endif

