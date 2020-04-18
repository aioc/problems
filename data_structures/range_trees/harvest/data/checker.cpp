#include<iostream>
#include <cassert>
#include <set>

using namespace std;

int N, Q, d,a,b;
string S;
const int MAX_N = 1e9;
const int MAX_Q = 1e5;
const int MAX_D = 1e9;

int main() {
    cin >> N >> Q;
    assert(1 <= N && N <= MAX_N && "Invalid number of trees");
    assert(1 <= Q && Q <= MAX_Q && "Invalid number of queries");
    int lastD = -1;
    for(int i = 0; i < Q; i++) {
        cin >> d >> a >> b;
        assert(d >= lastD && "Queries must be in non-descending order of d");
        assert(1 <= d && d <= MAX_D && "Invalid day");
        assert(1 <= a && a <= b && b <= N && "Invalid range for query");
        lastD = d;
    }
    int test;
    assert(!(cin >> test) && "There are more things at the end of the file!");
}
