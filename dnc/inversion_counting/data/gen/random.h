#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <fstream>
#include <tuple>
#include <cassert>
#include <queue>
#include <random>
#include <algorithm>

#ifndef RANDOM_H
#define RANDOM_H

using namespace std;

//
// Random functions
//
mt19937 generator;
bool generatorInitialised;
void initialiseGenerator(int seed) {
    generatorInitialised = true; 
    generator = mt19937(seed);
}

// Random int in [a, b]
int randint(int a, int b) {
    assert(a <= b);
    assert(generatorInitialised && "randint called before generator was initialised");
    uniform_int_distribution<int> distribution(a, b);
    return distribution(generator);
}

// Random int in [0, x)
int randint(int x) {
    return randint(0, x-1);
}

// Special hack for use with random_shuffle, as the overloads for randint confuse
// the compiler
int rndint(int x) {
    return randint(0, x-1);
}

// Random double in [a, b]
double randdouble(double a, double b) {
    assert(a < b);
    assert(generatorInitialised && "randdouble called before generator was initialised");
    uniform_real_distribution<double> distribution(a, b);
    return distribution(generator);
}

map<pair<int, int>, vector<int>> mv;
// Convenience method for returning a vector containing values in a given range [a, b], in order
vector<int> makerange(int a, int b) {
    if(mv.find({a, b}) == mv.end()) {
        vector<int> v;
        for(int i = a; i <= b; i++) {
            v.push_back(i);
        }
        mv[{a, b}] = v;
    }
    return mv[{a, b}];
}

vector<int> randpermutation(int l, int r) {
    auto perm = makerange(l, r);
    random_shuffle(perm.begin(), perm.end(), rndint);
    return perm;
}

// Returns a vector of given size with values in the range [minValue, maxValue]
vector<int> randvector(int size, int minValue, int maxValue) {
    vector<int> v;
    for(int i = 0; i < size; i++) {
        v.push_back(randint(minValue, maxValue));
    }
    return v;
}

// randvector, but the vector is sorted.
vector<int> randasc(int size, int minValue, int maxValue) {
    auto v = randvector(size, minValue, maxValue);
    sort(begin(v), end(v));
    return v;
}

vector<int> randdesc(int size, int minValue, int maxValue) {
    auto v = randvector(size, minValue, maxValue);
    sort(begin(v), end(v));
    reverse(begin(v), end(v));
    return v;
}

#endif // RANDOM_H
