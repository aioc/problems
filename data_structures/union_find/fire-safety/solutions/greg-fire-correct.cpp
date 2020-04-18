#include <iostream>

using namespace std;

int n, q, p[1000001], r[1000001], i, j;
char c;

int t(int i) {
    return p[i] = p[i] == i ? i : t(p[i]);
}

void u(int i, int j) {
    int x = t(i), y = t(j);
    if (x == y) return;
    if (r[x] < r[y]) p[x] = y;
    else if (r[x] > r[y]) p[y] = x;
    else p[y] = x, ++r[x];
}

int main() {
    cin >> n >> q;
    for (int i = 0; i ++< n;) p[i] = i;
    while (q --> 0) {
        cin >> c >> i;
        if (c == 'P') cin >> j, u(i, j);
        if (c == 'M') u(0, i);
        if (c == 'C') cout << (t(0) == t(i)) << '\n';
    }
    return 0;
}

