#include <iostream>
#include <cassert>

using namespace std;

int N, Q;

int main() {
    cin >> N >> Q;
    assert(1 <= N && N <= 1000000 && "Invalid N");
    assert(1 <= Q && Q <= 100000 && "Invalid Q");
    for(int i = 0; i < Q; i++) {
        char t;
        cin >> t;
        assert((t == 'P' || t == 'C' || t == 'M') && "Instruction char must be P C or M");
        int a, b;
        if (t == 'P') cin >> a >> b, assert(1 <= a && a <= N && 1 <= b && b <= N && "Invalid building indices");
        else if (t == 'C' || t == 'M') cin >> a, assert(1 <= a && a <= N && "Invalid building indices");
    }
    assert(cin.good());
    int test;
    assert(!(cin >> test) && "There are more things at the end of the file!");
}
