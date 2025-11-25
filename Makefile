CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = 

ARRAY_LIB = arrayLib
MATRIX_LIB = matrixLib
LOAD_LIB = load
MAIN_PROG = main

.PHONY: all clean info

# Расширения файлов для разных ОС
ifeq ($(OS),Windows_NT)
    LIB_EXT = .dll
    EXE_EXT = .exe
    LDFLAGS += -luser32
    LIB_LDFLAGS = -L. -l$(LOAD_LIB:%=$(subst lib,,%))
else
    LIB_EXT = .so
    EXE_EXT = 
    LDFLAGS += -ldl -Wl,-rpath,.
    LIB_LDFLAGS = -L. -l$(LOAD_LIB:lib%=%)
endif

all: $(LOAD_LIB)$(LIB_EXT) $(ARRAY_LIB)$(LIB_EXT) $(MATRIX_LIB)$(LIB_EXT) $(MAIN_PROG)$(EXE_EXT)

$(MAIN_PROG)$(EXE_EXT): Source.o $(LOAD_LIB)$(LIB_EXT)
	$(CC) -o $@ Source.o -L. -l$(LOAD_LIB) $(LDFLAGS)

$(LOAD_LIB)$(LIB_EXT): load.o
	$(CC) -shared -o $@ load.o $(LDFLAGS)

$(ARRAY_LIB)$(LIB_EXT): arrayMin.o
	$(CC) -shared -o $@ arrayMin.o

$(MATRIX_LIB)$(LIB_EXT): matrixMin.o
	$(CC) -shared -o $@ matrixMin.o

Source.o: Source.c load.h
	$(CC) $(CFLAGS) -c -o $@ Source.c

load.o: load.c load.h findMin.h
	$(CC) $(CFLAGS) -fPIC -c -o $@ load.c

arrayMin.o: arrayMin.c findMin.h
	$(CC) $(CFLAGS) -fPIC -c -o $@ arrayMin.c

matrixMin.o: matrixMin.c findMin.h
	$(CC) $(CFLAGS) -fPIC -c -o $@ matrixMin.c

clean:
	del *.o *.dll *.so *.exe $(MAIN_PROG)