#include "vector.h"
#include <malloc.h>
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

void badAlloc() {
    fprintf(stderr, "bad alloc");
    exit(1);
}

void emptyVector() {
    fprintf(stderr, "vector is empty");
    exit(1);
}

void badIndex(const size_t index) {
    fprintf(stderr, "IndexError: a[%d] is not exists", index);
    exit(1);
}

vector createVector(const size_t capacity) {
    int *data = NULL;
    if (capacity > 0) {
        data = (int *) malloc(sizeof(int) * capacity);
        if (data == NULL)
            badAlloc();
    }

    return (vector) {data, 0, capacity};
}

void reserve(vector *v,  size_t newCapacity) {
    v->capacity = newCapacity;
    if (v->capacity < v->size)
        v->size = v->capacity;

    if (newCapacity > 0) {
        v->data = (int *) realloc(v->data, sizeof(int) * newCapacity);
        if (v->data == NULL)
            badAlloc();
    } else
        v->data = NULL;
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

void deleteVector(vector *v) {
    reserve(v, 0);
}

bool isEmptyVector(vector *v) {
    return v->size == 0;
}
bool isZeroVector(vector *v){
    return v->capacity == 0;
}

bool isFullVector(vector *v){
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i){
    return v->data[i];
}

void pushBack(vector *v, const int x) {
    if (isFullVector(v) && !isZeroVector(v))
        reserve(v, v->size * 2);
    else if (isZeroVector(v))
        reserve(v, 1);

    v->data[v->size++] = x;
}

void popBack(vector *v) {
    if (isEmptyVector(v))
        emptyVector();

    v->size--;
}