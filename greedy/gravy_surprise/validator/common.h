#ifndef H_COMMON
#define H_COMMON
#include "testlib.h"
#include "bounds.h"
#include <iostream>

using namespace std;


class Checker {
public:
    int N, K;

    Checker() {};

    void validate() {
        registerValidation();
        N = inf.readInt(MIN_N, MAX_N, "N");
        inf.readSpace();
        K = inf.readInt(1, N, "K");
        inf.readEoln();

        inf.readInts(N, MIN_TASTE, MAX_TASTE);
        inf.readEoln();
        inf.readEof();
    }
};

#endif // COMMON_H
