#include "common.h"
#include "bounds.h"

int main() {
    Checker c{}; c.validate();
    ensuref(c.K == 2, "Does not match sub1 bounds");
    return 0;
}
