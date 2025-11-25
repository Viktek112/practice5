// ----------------------- load.c
#include "load.h"
#include "findMin.h"
#include <stdio.h>
#include <windows.h>
void LoadRun(const char* const s, const int* const p, int size) {
	void* lib;
	void (*findMin)(const int* const p, int size);
	lib = LoadLibrary(s); //загрузка библиотеки в память;
	if (!lib) {
		printf("cannot open library '%s'\n", s); 
		return;
	}
	findMin = (void (*)(const int* const p, int size))GetProcAddress((HINSTANCE)lib, "findMin"); //получение указателя на функцию из библиотеки;
	if (findMin == NULL) {
		printf("cannot load function func\n");
	}
	else {
		findMin(p, size);
	}
	FreeLibrary((HINSTANCE)lib); //выгрузка библиотеки;
}


