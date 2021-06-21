#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TO(T) *(T*)

#define bool int
#define true 1
#define false 0

#define MAXINT 1000000000
#define MAXLL 1000000000000000000

#define min(x,y) (((x) < (y)) ? (x) : (y))
#define max(x,y) (((x) > (y)) ? (x) : (y))

#define ESC 27

void FatalError(const char* message);

void* Malloc(long long ByteCount);

typedef struct Vector Vector;
struct Vector {
    int elemsize;
    int size;
    void* begin;
    int alloc;
    bool (*comp) (void* a, void* b);
};

Vector* VectorNew(int sizeof_element);
void VectorDelete(Vector* that);
void VectorClear(Vector* that);
void VectorAddElem(Vector* that, void* what);
void VectorDelElem(Vector* that, int index);
int VectorSize(Vector* that);
void* VectorGetElem(Vector* that, int index);
void VectorSetElem(Vector* that, int index, void* what);
int VectorFindElem(Vector* that, void* what);
int VectorFindLastElem(Vector* that, void* what);
bool VectorContainElem(Vector* that, void* what);
void VectorRealloc(Vector* that, int newalloc);

/* Строка */
typedef Vector String;
String* StringNew(void); /* Конструирует строку и возвращает указатель на неё */
void StringDelete(String* that); /* Деструктор строки */
void StringClear(String* that); /* Очищает строку */
void StringAddElem(String* that, char what); /* Добавляет в конец строки символ */
int StringSize(String* that); /* Возвращает длину строки */

void StringRead(String* that, char until, FILE* from); /* Читает строку между двумя символами, являющимися переносом, пробелом или until-символом */
void StringIgnore(FILE* from); /* Переносит курсор чтения на следующую строку */

bool StringToInt(char* from, long long* towhat, long long MinBound, long long MaxBound); /* Пытается преобразовать строку в целое число в пределах [MinBound, MaxBound] */

long long StringReadInt(FILE* from, long long MinBound, long long MaxBound); /* Запрашивает целое число в пределах [MinBound, MaxBound] */

/* Сравнение данных */
bool OperEqual(void* a, void* b, bool (*cmp)(void*, void*));

bool CmpChar(void* a, void* b);
/* Сравнение данных */

#endif