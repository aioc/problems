#include "common.h"
#include "bounds.h"

int main() {
    Checker c{}; c.validate();
    ensuref(c.N <= 100, "Does not match sub3 bounds");
    return 0;
}
