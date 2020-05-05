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
    if(argc != 3) {
        cerr << "Usage: " << argv[0] << " <N> <seed>\n";
        return 1;
    }
    int N = stoi(argv[1]);
    int seed = stoi(argv[2]);
    
    char fileName[12345];
    sprintf(fileName, "random-%d-%d.in", N, seed);
    ofstream out(fileName);
    out << N << "\n";
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(j != 0) {
                out << " ";
            }
            out << randint(MIN_B, MAX_B);
        }
        out << "\n";
    }
}
