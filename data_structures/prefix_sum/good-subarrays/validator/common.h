#ifndef H_COMMON
#define H_COMMON
#include "testlib.h"
#include <iostream>

using namespace std;

int validate(int MAX_N, int MAX_VAL) {
	registerValidation();
    int N = inf.readInt(0, MAX_N, "N");
    inf.readEoln();
    inf.readInts(N, 0, MAX_VAL);
    inf.readEoln();
    inf.readEof();
    return 0;
}

#endif // COMMON_H
