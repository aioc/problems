#include <iostream>
#include <cstdlib>

using namespace std;

int N, Q, pipeInstalls, mainInstalls, checks, seed;

int randint(int a, int b) {
    return rand() % (b - a + 1) + a;
}

int main(int argc, char **argv) {
    if (argc != 6) {
        cerr << "Usage: " << argv[0] << " N pipeInstalls mainInstalls checks seed\n";
        return 1;
    }
    N = stoi(argv[1]);
    pipeInstalls = stoi(argv[2]);
    mainInstalls = stoi(argv[3]);
    checks = stoi(argv[4]);
    seed = stoi(argv[5]);
    Q = pipeInstalls + mainInstalls + checks;
    if (Q > 100000 || Q < 1 || N < 1 || N > 1000000) {
        cerr << "Insane case\n";
        return 2;
    }
    cout << N << ' ' << Q << '\n';
    srand(seed);
    while (Q --> 0) {
        // distribute probability by remaining ratio, but weight mains double
        int x = randint(-mainInstalls, Q);
        if (x < mainInstalls) {
            --mainInstalls;
            // duplicates allowed
            cout << "M " << randint(1, N) << '\n';
        }
        else if (x < mainInstalls + pipeInstalls) {
            --pipeInstalls;
            // not necessarily distinct
            cout << "P " << randint(1, N) << ' ' << randint(1, N) << '\n';
        }
        else {
            --checks;
            cout << "C " << randint(1, N) << '\n';
        }
    }
    return 0;
}

