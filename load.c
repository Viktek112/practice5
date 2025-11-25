// ----------------------- load.c
#include "load.h"
#include "findMin.h"
#include <stdio.h>
#include <dlfcn.h>
void LoadRun(const char* const s, const int* const p, int size) {
	void* lib;
	void (*findMin)(const int* const p, int size);
	lib = dlopen(s,RTLD_LAZY); //загрузка библиотеки в память;
	if (!lib) {
		printf("cannot open library '%s'\n", s);
		return;
	}
	findMin = (void (*)(const int* const p, int size))dlsym(lib, "run"); //получение указателя на функцию из библиотеки;
	if (findMin == NULL) {
		printf("cannot load function func\n");
	}
	else {
		findMin(p, size);
	}
	dlclose(lib); //выгрузка библиотеки;
}


