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
void test_atVector_notEmptyVector() {
    vector v = (vector) {(int[]){1, 2, 3}, 3, 3};
    assert(*atVector(&v, 0) == 1);
    assert(*atVector(&v, 1) == 2);
    assert(*atVector(&v, 2) == 3);

    deleteVector(&v);
}
void test_atVector_requestToLastElement() {
    vector v = (vector) {(int[]){1, 2, 3}, 3, 3};
    assert(*atVector(&v, v.size - 1) == 3);

    deleteVector(&v);
}

void test_back_oneElementInVector() {
    vector v = (vector) {(int[]){1}, 1, 1};
    assert(*back(&v) == 1);

    deleteVector(&v);
}
void test_front_oneElementInVector() {
    vector v = (vector) {(int[]){1}, 1, 1};
    assert(*front(&v) == 1);

    deleteVector(&v);
}
