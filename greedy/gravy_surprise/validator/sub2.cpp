#include "common.h"
#include "bounds.h"

int main() {
    Checker c{}; c.validate();
    ensuref(c.K == 3, "Does not match sub2 bounds");
    return 0;
}
