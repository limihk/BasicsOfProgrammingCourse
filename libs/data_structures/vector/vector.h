
#ifndef LABA_5B_VECTOR_H
#define LABA_5B_VECTOR_H
#include <stdio.h>
#include "../../algorithms/array/array.h"

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


#endif //LABA_5B_VECTOR_H