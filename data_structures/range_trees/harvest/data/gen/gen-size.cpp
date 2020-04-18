#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <set>

using namespace std;
const int MAX_A = 1e9;

int randint(int l, int r) {
    int d = r-l+1;
    return l + rand()%d;
}

int myrand(int x) {
    return randint(0, x-1);
}

int a[123456];

struct range {
    range(int _d, int _l, int _r) : d{_d}, l{_l}, r{_r} {};
    int d, l, r;
    const bool operator<(const range& o) const {
        return d < o.d;
    }
};

int main(int argc, char* argv[]) {
    if(argc != 8) {
        cerr << "Usage: " << argv[0] << " <N> <Q> <minD> <maxD> <minR> <maxR> <seed>\n";
        return 1;
    }
    int N = stoi(argv[1]);
    int Q = stoi(argv[2]);
    int minD = stoi(argv[3]);
    int maxD = stoi(argv[4]);
    int minR = stoi(argv[5]);
    int maxR = stoi(argv[6]);
    int seed = stoi(argv[7]);
    
    srand(seed);
    
    char fileName[12345];
    sprintf(fileName, "size-%d.in", seed);
    ofstream out(fileName);
   
    vector<range> v;
    for(int i = 1; i <= Q; i++) {
        int si = randint(minR, maxR);
        int l = randint(1, N-si+1);
        int r = l + si - 1;
        int d = randint(minD, maxD);
        if(l > r) swap(l, r);
        v.emplace_back(d, l, r);
    }

    random_shuffle(v.begin(), v.end(), myrand);
    sort(v.begin(), v.end());

    out << N << " " << Q << "\n";
    for(auto x: v) {
        out << x.d << " " << x.l << " " << x.r << "\n";
    }
}
