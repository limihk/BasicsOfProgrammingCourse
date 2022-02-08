#include "test_vector.h"
#include "../vector.h"
#include <assert.h>

void test_pushBack_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 1);
    assert(v.size == 1 && v.capacity == 1);

    deleteVector(&v);
}

void test_pushBack_FullVector() {
    vector v = (vector) {(int[]) {1}, 1, 5};
    pushBack(&v, 2);
    assert(v.size == 2 && v.capacity == 5);

    deleteVector(&v);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert (v.size == 1);
    popBack(&v);
    assert (v.size == 0);
    assert (v.capacity == 1);
}
