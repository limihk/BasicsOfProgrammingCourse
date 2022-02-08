#include "libs/data_structures/vector/vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include <assert.h>


#include "libs/data_structures/vector/TestVector/test_vector.h"


void test() {
    test_pushBack_emptyVector();
    test_pushBack_FullVector();
    test_popBack_notEmptyVector();

    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();


}


int main() {

    test();

    return 0;
}
