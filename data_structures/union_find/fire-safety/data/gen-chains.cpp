#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cassert>

using namespace std;

int N, Q, n, chains, mainsDuring, mainsAfter, joinsDuring, joinsAfter, checksDuring, checksAfter, seed;

int randint(int a, int b) {
    return rand() % (b - a + 1) + a;
}

// picks weighting sides and centre higher
int weightedPick(int max) {
    int m = max / 4, y = randint(0, m);
    int d = (m * m - y * y) / m; // quadratically weighted towards 0
    switch (randint(0, 3)) {
        case 0: return 1 + d; // left
        case 3: return max - d; // right
        case 1: return max / 2 - d; // left of centre
        case 2: return max / 2 + d; // right of centre
    }
    assert(false);
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 10) {
        cerr << "Usage: " << argv[0] << " n chains mainsDuring mainsAfter joinsDuring joinsAfter checksDuring checksAfter seed\n";
        return 1;
    }
    n = stoi(argv[1]);
    chains = stoi(argv[2]);
    mainsDuring = stoi(argv[3]);
    mainsAfter = stoi(argv[4]);
    joinsDuring = stoi(argv[5]);
    joinsAfter = stoi(argv[6]);
    checksDuring = stoi(argv[7]);
    checksAfter = stoi(argv[8]);

    seed = stoi(argv[9]);
    srand(seed);

    int chainJoins = n - chains;

    N = 1000000;
    Q = mainsDuring + mainsAfter + joinsDuring + joinsAfter + checksDuring + checksAfter + chainJoins;
    if (n < 1 || n > N || chains < 1 || chains > n || Q < 1 || Q > 100000) {
        cerr << "Insane case\n";
        return 2;
    }
    cout << N << ' ' << Q << '\n';

    // build chains
    int p[N];
    for (int i = 0; i < N; ++i) p[i] = i + 1;
    random_shuffle(p, p + N);

    int len = n / chains;

    int md = mainsDuring, jd = joinsDuring, cd = checksDuring;

    for (int i = 0, j = 0; j < n; ++i) {
        int end = j + len * 2 > n ? n : j + len; // last chain can be up to 2len-1
        for (int j0 = j; j < end; ++j) {
            if (j > j0) {
                cout << "P " << p[j-1] << ' ' << p[j] << '\n';
                --Q;
            }

            // ~mainsDuring / n probability
            if (md && randint(0, n) < mainsDuring) --md, --Q, cout << "M " << p[j] << '\n';

            if (jd && randint(0, n) < joinsDuring) {
                --jd, --Q;
                // join ends or middle
                int ap = randint(0, 3), bp = randint(0, j - j0 > len / 2 ? 2 : 1);
                int a = (ap == 0 ? 0 : ap == 1 ? len - 1 : len / 2) + randint(0, i) * len;
                int b = (bp == 0 ? 0 : bp == 1 ? min(len / 2, j - j0) : j - j0) + j0;
                cout << "P " << p[a] << ' ' << p[b] << '\n';
            }

            if (cd && randint(0, n) < checksDuring) --cd, --Q, cout << "C " << p[j] << '\n';
        }
    }

    // complete unfinished allocation
    md += mainsAfter, jd += joinsAfter, cd += checksAfter;
    while (Q --> 0) {
        int x = randint(0, md + jd + cd);
        int a = p[weightedPick(len) + randint(0, chains-1) * len];
        if (x < md) {
            // main
            cout << "M " << a << '\n';
            --md;
        }
        else if (x < md + jd) {
            // join
            int b = p[weightedPick(len) + randint(0, chains-1) * len];
            cout << "P " << a << ' ' << b << '\n';
            --jd;
        }
        else {
            // check
            cout << "C " << a << '\n';
            --cd;
        }
    }

    return 0;
}

