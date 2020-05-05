#include <iostream>
#include <cassert>
#include <set>
#include <sstream>

using namespace std;

int N;

int main() {
    cin >> N;
    cin.ignore();
    assert(1 <= N && N <= 15 && "Invalid number of jobs/interns");
    
    for(int i = 0; i < N; i++) {
        stringstream ss;
        string s;
        getline(cin, s);
        ss << s;
        for(int j = 0; j < N; j++) {
            int a;
            assert(ss >> a && "Invalid number of integers on this row");
            assert(10 <= a && a <= 100 && "Each integer must be between 10 and 100 (inclusive)");
        }
        char c;
        assert(!(ss >> c) && "Extraneous data on this line");
    }

    char test;
    assert(!(cin >> test) && "There are more things at the end of the file!");
}
