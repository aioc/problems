#include <vector>

#include "random.h"

using namespace std;

const int MAX_N = 1e5;

void printCase(string name, vector<int> a) {
    ofstream out(name);
    out << a.size() << "\n";
    bool first = true;
    for(auto x: a) {
        if(first) {
            first = false;
        } else {
            out << " ";
        }
        out << x;
    }
    out << "\n";
}

int main() {
    initialiseGenerator(1239768);

    vector<int> s = makerange(1, MAX_N);
    printCase("sorted.in", s);
    reverse(s.begin(), s.end());
    printCase("rev-sorted.in", s);

    printCase("sorted-2.in", randasc(MAX_N, 1, 10));
    printCase("rev-sorted-2.in", randdesc(MAX_N, 1, 10));

    printCase("random-1.in", randvector(MAX_N, 1, MAX_N));
    printCase("random-2.in", randvector(MAX_N, 1, MAX_N));
    printCase("random-3.in", randvector(MAX_N, 1, 30));
    printCase("random-4.in", randvector(MAX_N, 1, 300));

    vector<int> valley;
    for(int i = MAX_N/2; i >= 1; i--) {
        valley.push_back(i);
    }
    for(int i = 1; i < MAX_N/2; i++) {
        valley.push_back(i);
    }
    printCase("valley.in", valley);
}
