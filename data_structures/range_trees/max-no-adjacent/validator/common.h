#ifndef H_COMMON
#define H_COMMON
#include "testlib.h"
#include "bounds.h"
#include <iostream>

using namespace std;


class Checker {
public:
    Checker() {};

    void validate() {
        registerValidation();
        int N = inf.readInt(MIN_N, MAX_N, "N");
        inf.readSpace();
        int B = inf.readInt(MIN_B, MAX_B, "B");
        inf.readEoln();

        inf.readInts(N, MIN_A, MAX_A, "A");
        inf.readEoln();

        bool sawQuery = false;
        for(int _i = 0; _i < B; _i++) {
            char op = inf.readChar();
            inf.readSpace();

            if(op == 'U') {
                inf.readInt(1, N, "i");
                inf.readSpace();
                inf.readInt(MIN_A, MAX_A, "x");
            } else if(op == 'Q') {
                int l = inf.readInt(1, N, "l");
                inf.readSpace();
                inf.readInt(l, N, "r");
                sawQuery = true;
            } else {
                ensuref(false, "Op must be one of U or Q");
            }
            inf.readEoln();
        }
        ensuref(sawQuery, "Must have at least one query");
        inf.readEof();
    }
};

#endif // COMMON_H
