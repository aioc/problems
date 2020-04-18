#include <iostream>
#include <utility>
#include <cassert>

using namespace std;

#define TREE 20000000

int n, q, d, a, b, p, l[TREE], r[TREE], z = 1;
long long t[TREE], g[TREE];

// process resets and propagate changes to children
void pp(int i, int s, int e) {
    if (!i) return;
    // very negative -> propagate reset to children (if exist), do reset
    if (g[i] < 0) g[l[i]] = g[r[i]] = -(1L << 62), g[i] += 1L << 62, t[i] = 0;
    if (g[i]) {
        t[i] += g[i] * (long long)(e - s + 1);
        g[l[i]] += g[i];
        g[r[i]] += g[i];
        g[i] = 0;
    }
}

// returns (deleted, remaining)
pair<long long, long long> h(int a, int b, int i = 1, int s = 1, int e = 0) {
    if (!i) return { 0, 0 };
    if (e < 1) e = n;
    // process resets if any, propagate to children if any
    pp(i, s, e);
    if (a == s && b == e) {
        // reset the entire node and return count
        g[i] = -(1L << 62);
        return { t[i], 0 };
    }
    int m = (s + e) / 2;
    // create children if they don't exist
    if (!l[i] || !r[i]) {
        assert(!l[i] && !r[i]);
        l[i] = ++z, r[i] = ++z;
        long long x = t[i] / (e - s + 1);
        g[l[i]] = g[r[i]] = x;
    }
    // propagate the children downwards so their tree value is correct
    pp(l[i], s, m), pp(r[i], m + 1, e);
    // if we don't look at a child, 0 deleted and whatever's there remaining
    pair<long long, long long> x = { 0, t[l[i]] }, y = { 0, t[r[i]] };
    if (a <= m) x = h(a, min(b, m), l[i], s, m);
    if (b > m) y = h(max(a, m + 1), b, r[i], m + 1, e);
    // deleted whatever the children deleted, their sum remains
    return { x.first + y.first, t[i] = x.second + y.second };
}

int main() {
    cin >> n >> q;
    while (q --> 0) {
        cin >> d >> a >> b;
        g[1] += d - p;
        cout << h(a, b).first << '\n';
        p = d;
    }
    return 0;
}
