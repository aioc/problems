#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <set>

using namespace std;

int randint(int l, int r) {
    int d = r-l+1;
    return l + rand()%d;
}

int myrand(int x) {
    return randint(0, x-1);
}

const int MIN_B = 10;
const int MAX_B = 100;

int main(int argc, char* argv[]) {
    if(argc != 6) {
        cerr << "Usage: " << argv[0] << " <N> <A> <B> <dir> <seed>\n";
        return 1;
    }
    int N = stoi(argv[1]);
    int A = stoi(argv[2]);
    int B = stoi(argv[3]);
    int dir = stoi(argv[4]);
    int seed = stoi(argv[5]);
    
    char fileName[12345];
    sprintf(fileName, "diag-%d-%d-%d-%d-%d.in", N, A, B, dir, seed);
    ofstream out(fileName);

    out << N << "\n";
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(j != 0) {
                out << " ";
            }
            if(dir) {
                out << (j + i == N - 1 ? A : B);
            } else {
                out << (i == j ? A : B);
            }
        }
        out << "\n";
    }
}
