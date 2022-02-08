
#ifndef LABA_5B_VECTOR_H
#define LABA_5B_VECTOR_H

#include <stdio.h>
#include "../../algorithms/array/array.h"
#include <stdbool.h>

typedef struct vector {
    int *data;
    size_t size;
    size_t capacity;


} vector;


//возвращает структуру-дескриптор вектор из n значений.
vector createVector(size_t capacity);

//изменяет количество памяти, выделенное под хранение элементов вектора v.
void reserve(vector *v, size_t newCapacity);

//удаляет элементы из контейнера, но не освобождает выделенную память вектора v.
void clear(vector *v);

//освобождает память, выделенную под неиспользуемые элементы вектора v.
void shrinkToFit(vector *v);

//освобождает память, выделенную вектору v.
void deleteVector(vector *v);

//возврашает:
//1, если вектор v пустой;
//0, если хотя бы имеется один элемент.
bool isEmptyVector(vector *v);

//возврашает:
//1, если вектор v полный;
//0, если хотя бы не достаёт одного элемента.
bool isFullVector(vector *v);

//возврашает:
//1, если вектор v нулевой;
//0, если нет.
bool isZeroVector(vector *v);

//возвращает i-ый элемент вектора v.
int getVectorValue(vector *v, size_t index);

//добавляет элемент x в конец вектора v.
void pushBack(vector *v, int x);

//удаляет последний элемент из вектора v.
void popBack(vector *v);

//возвращает указатель на index-ый элемент вектора
int* atVector(vector *v, size_t index);

//возвращает указатель на последний элемент
int* back(vector *v);

//Возвращает указатель на первый элемент
int* front(vector *v);


#endif //LABA_5B_VECTOR_H