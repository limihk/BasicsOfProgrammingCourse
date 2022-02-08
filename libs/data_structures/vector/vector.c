#include "vector.h"
#include <malloc.h>
#include <assert.h>

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

void reserve(vector *v, const size_t newCapacity) {
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